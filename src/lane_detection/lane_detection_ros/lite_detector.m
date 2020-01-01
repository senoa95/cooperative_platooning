close all
clear
clc

%% initialize camara intrinsics
% focalLength = cameraParams.FocalLength
% principalPoint = cameraParams.PrincipalPoint
% imageSize = cameraParams.ImageSize

% focalLength = [94.0798, 94.8510];
% principalPoint = [321.4176, 159.4088];



focalLength = [637.8722,637.0641];
principalPoint = [323.5977,239.8220];
imageSize      = [480, 640];  
camIntrinsics = cameraIntrinsics(focalLength, principalPoint, imageSize);

%% determine camera sensor placement
height = 0.3;    % mounting height in meters from the ground
pitch  = 0;        % pitch of the camera in degrees
sensor = monoCamera(camIntrinsics, height, 'Pitch', pitch);
%% initialize matlab ros node
Ts = 0.1;
PredictionHorizon = 2;
% center_curvature_derivative.Data = 0;
% center_curvature.Data = 0;
% center_relative_yaw_angle.Data = 0; 
% center_lateral_deviation.Data = 0;

if ros.internal.Global.isNodeActive == 0
    rosinit
end

meanCounter = 0;

mean_right_curvature_rate = 0;
mean_right_curvature = 0;
mean_right_relative_yaw_angle = 0;
mean_right_lateral_deviation = 0;

mean_left_curvature_rate = 0;
mean_left_curvature = 0;
mean_left_relative_yaw_angle = 0;
mean_left_lateral_deviation = 0;
    
while true
%% subscribe to compressed camera image
cam_topic = '/usb_cam/image_raw/compressed';
sub = rossubscriber(cam_topic);
msg = sub.receive;
frame = msg.readImage;

%% specify lane detection parameters
distAheadOfSensor = 55; % in meters, as previously specified in monoCamera height input
spaceToOneSide    = 10;  % all other distance quantities are also in meters
bottomOffset      = 2;

outView   = [bottomOffset, distAheadOfSensor, -spaceToOneSide, spaceToOneSide]; % [xmin, xmax, ymin, ymax]
imageSize = [NaN, 640]; % output image width in pixels; height is chosen automatically to preserve units per pixel ratio

%% transform image
birdsEyeConfig = birdsEyeView(sensor, outView, imageSize);

birdsEyeImage = transformImage(birdsEyeConfig, frame);

% Convert to grayscale
birdsEyeImage = rgb2gray(birdsEyeImage);

% Lane marker segmentation ROI in world units
vehicleROI = outView - [0, 0, -0.85, 0.85]; % look 3 meters to left and right, and 4 meters ahead of the sensor
approxLaneMarkerWidthVehicle = 0.15; % centimeters

%% detect lane 
% Detect lane features
laneSensitivity = 0.2;
birdsEyeViewBW = segmentLaneMarkerRidge(birdsEyeImage, birdsEyeConfig, approxLaneMarkerWidthVehicle,...
    'ROI', vehicleROI, 'Sensitivity', laneSensitivity);

[imageX, imageY] = find(birdsEyeViewBW);
xyBoundaryPoints = imageToVehicle(birdsEyeConfig, [imageY, imageX]);

maxLanes      = 2; % look for maximum of two lane markers
boundaryWidth = 3*approxLaneMarkerWidthVehicle; % expand boundary width

[boundaries, boundaryPoints] = findCubicLaneBoundaries(xyBoundaryPoints,boundaryWidth, ...
    'MaxNumBoundaries', maxLanes, 'validateBoundaryFcn', @validateBoundaryFcn);

%% filter lanes
% Establish criteria for rejecting boundaries based on their length
maxPossibleXLength = diff(vehicleROI(1:2));
minXLength         = maxPossibleXLength * 0.60; % establish a threshold

% Reject short boundaries
isOfMinLength = arrayfun(@(b)diff(b.XExtent) > minXLength, boundaries);
boundaries    = boundaries(isOfMinLength);

%% convert lanes to vehicle frame
% To compute the maximum strength, assume all image pixels within the ROI
% are lane candidate points
birdsImageROI = vehicleToImageROI(birdsEyeConfig, vehicleROI);
[laneImageX,laneImageY] = meshgrid(birdsImageROI(1):birdsImageROI(2),birdsImageROI(3):birdsImageROI(4));

% Convert the image points to vehicle points
vehiclePoints = imageToVehicle(birdsEyeConfig,[laneImageX(:),laneImageY(:)]);

% Find the maximum number of unique x-axis locations possible for any lane
% boundary
maxPointsInOneLane = numel(unique(vehiclePoints(:,1)));

% Set the maximum length of a lane boundary to the ROI length
maxLaneLength = diff(vehicleROI(1:2));

% Compute the maximum possible lane strength for this image size/ROI size
% specification
maxStrength   = maxPointsInOneLane/maxLaneLength;

% Reject weak boundaries
isStrong      = [boundaries.Strength] > 0.4*maxStrength;
boundaries    = boundaries(isStrong);

boundaries = classifyLaneTypes(boundaries, boundaryPoints);

% Locate two ego lanes if they are present
xOffset    = 0;   %  0 meters from the sensor
distanceToBoundaries  = boundaries.computeBoundaryModel(xOffset);

% Find candidate ego boundaries
leftEgoBoundaryIndex  = [];
rightEgoBoundaryIndex = [];
minLDistance = min(distanceToBoundaries(distanceToBoundaries>0));
minRDistance = max(distanceToBoundaries(distanceToBoundaries<=0));
if ~isempty(minLDistance)
    leftEgoBoundaryIndex  = distanceToBoundaries == minLDistance;
end
if ~isempty(minRDistance)
    rightEgoBoundaryIndex = distanceToBoundaries == minRDistance;
end

leftEgoBoundary       = boundaries(leftEgoBoundaryIndex);
rightEgoBoundary      = boundaries(rightEgoBoundaryIndex);

%% display left and right lane clothoid parameters

if isempty(leftEgoBoundary)
    if ~isempty(rightEgoBoundary)
%         get right lane values
        disp('right lane params')
        disp(rightEgoBoundary.Parameters)
        right_strength = rightEgoBoundary.Strength;
        right_curvature_rate = rightEgoBoundary.Parameters(1);
        right_curvature = rightEgoBoundary.Parameters(2);
        right_relative_yaw_angle = rightEgoBoundary.Parameters(3);
        right_lateral_deviation = rightEgoBoundary.Parameters(4);
        
        centerEgoBoundary = rightEgoBoundary; %assign center lane to left lane;
        
%         pack left lane values with zeros. Set strength to 0.
        disp('left lane not detected')
        left_strength = -100;
        left_curvature_rate = 100;
        left_curvature = 100;
        left_relative_yaw_angle = 100;
        left_lateral_deviation = 100;
    else
%         if both left and right lanes not detected continue
        disp('no lanes detected. continuing')
        [birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
    %     clear centerEgoBoundary
        subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
        imshow(birdsEyeWithEgoLane)
        subplot('Position', [0.5, 0, 0.5, 1.0])
        imshow(frameWithEgoLane)
        continue
    end
else
%   get left lane values
    disp('left lane params')
    disp(leftEgoBoundary.Parameters)
    left_strength = leftEgoBoundary.Strength;
    left_curvature_rate = leftEgoBoundary.Parameters(1);
    left_curvature = leftEgoBoundary.Parameters(2);
    left_relative_yaw_angle = leftEgoBoundary.Parameters(3);
    left_lateral_deviation = leftEgoBoundary.Parameters(4);
    
    centerEgoBoundary = leftEgoBoundary; %assign center lane to left lane;
    
%   get right lane values
    if ~isempty(rightEgoBoundary)
        disp('right lane params')
        disp(rightEgoBoundary.Parameters)
        right_strength = rightEgoBoundary.Strength;
        right_curvature_rate = rightEgoBoundary.Parameters(1);
        right_curvature = rightEgoBoundary.Parameters(2);
        right_relative_yaw_angle = rightEgoBoundary.Parameters(3);
        right_lateral_deviation = rightEgoBoundary.Parameters(4);
    else
%         pack right lane values with zeros. Set strength to 0.
        disp('right lane not detected')
        right_strength = -100;
        right_curvature_rate = 100;
        right_curvature = 100;
        right_relative_yaw_angle = 100;
        right_lateral_deviation = 100;
    end
end


meanCounter = meanCounter + 1;
meanRange = 5;
rightMeanCounter = 0;
leftMeanCounter = 0;

if meanCounter == meanRange
    meanCounter = 0;
%     [birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,leftEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);

% if ~isempty(leftEgoBoundary) || ~isempty(rightEgoBoundary)
        
    computeCenter = 0;
    
    if rightMeanCounter > 1 && ~isempty(rightEgoBoundary)
        rightEgoBoundary.Parameters(1) = mean_right_curvature_rate/meanRange;
        rightEgoBoundary.Parameters(2) = mean_right_curvature/meanRange;
        rightEgoBoundary.Parameters(3) = mean_right_relative_yaw_angle/meanRange;
        rightEgoBoundary.Parameters(4) = mean_right_lateral_deviation/meanRange;
    end
    
    if leftMeanCounter > 1 && ~isempty(leftEgoBoundary)
        leftEgoBoundary.Parameters(1) = mean_left_curvature_rate/meanRange;
        leftEgoBoundary.Parameters(2) = mean_left_curvature/meanRange;
        leftEgoBoundary.Parameters(3) = mean_left_relative_yaw_angle/meanRange;
        leftEgoBoundary.Parameters(4) = mean_left_lateral_deviation/meanRange;
    end
    
    if computeCenter
        sim('estimate_lane_center.slx')
        centerEgoBoundary.Parameters(1) = mean(center_curvature_derivative.Data);
        centerEgoBoundary.Parameters(2) = mean(center_curvature.Data(1,:));
        centerEgoBoundary.Parameters(3) = mean(center_relative_yaw_angle.Data);
        centerEgoBoundary.Parameters(4) = mean(center_lateral_deviation.Data);
        disp('CENTER lane params')
        disp(centerEgoBoundary.Parameters)

        [birdsEyeWithEgoLane,frameWithEgoLane] = showLanesWithCenter(birdsEyeImage,leftEgoBoundary,centerEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
    %     clear centerEgoBoundary
        subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
        imshow(birdsEyeWithEgoLane)
        subplot('Position', [0.5, 0, 0.5, 1.0])
        imshow(frameWithEgoLane)
    else
        [birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
        subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
        imshow(birdsEyeWithEgoLane)
        subplot('Position', [0.5, 0, 0.5, 1.0])
        imshow(frameWithEgoLane)
    end
    
    mean_right_curvature_rate = 0;
    mean_right_curvature = 0;
    mean_right_relative_yaw_angle = 0;
    mean_right_lateral_deviation = 0;
    
    mean_left_curvature_rate = 0;
    mean_left_curvature = 0;
    mean_left_relative_yaw_angle = 0;
    mean_left_lateral_deviation = 0;
    
    rightMeanCounter = 0;
    rightMeanCounter = 0;      
    
else
    if ~isempty(rightEgoBoundary)
    mean_right_curvature_rate = mean_right_curvature_rate + right_curvature_rate;
    mean_right_curvature = mean_right_curvature + right_curvature;
    mean_right_relative_yaw_angle = mean_right_relative_yaw_angle + right_relative_yaw_angle;
    mean_right_lateral_deviation = mean_right_lateral_deviation + right_lateral_deviation;
    rightMeanCounter = rightMeanCounter + 1;
    end
    
    if ~isempty(leftEgoBoundary)
    mean_left_curvature_rate = mean_left_curvature_rate + right_curvature_rate;
    mean_left_curvature = mean_left_curvature + right_curvature;
    mean_left_relative_yaw_angle = mean_left_relative_yaw_angle + right_relative_yaw_angle;
    mean_left_lateral_deviation = mean_left_lateral_deviation + right_lateral_deviation;
    leftMeanCounter = leftMeanCounter + 1;
    end
end

        
    
% else
%     continue
% end
end
%% supporting functions

function [birdsEyeWithEgoLane,frameWithEgoLane] =showLanes(birdsEyeImage,leftEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor)

xVehiclePoints = bottomOffset:distAheadOfSensor;
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeImage, leftEgoBoundary , birdsEyeConfig, xVehiclePoints, 'Color','Red');
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, rightEgoBoundary, birdsEyeConfig, xVehiclePoints, 'Color','Green');

frameWithEgoLane = insertLaneBoundary(frame, leftEgoBoundary, sensor, xVehiclePoints, 'Color','Red');
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, rightEgoBoundary, sensor, xVehiclePoints, 'Color','Green');
end

function [birdsEyeWithEgoLane,frameWithEgoLane] =showLanesWithCenter(birdsEyeImage,leftEgoBoundary,centerEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor)

xVehiclePoints = bottomOffset:distAheadOfSensor;
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeImage, leftEgoBoundary , birdsEyeConfig, xVehiclePoints, 'Color','Red');
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, centerEgoBoundary, birdsEyeConfig, xVehiclePoints, 'Color','Blue');
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, rightEgoBoundary, birdsEyeConfig, xVehiclePoints, 'Color','Green');

frameWithEgoLane = insertLaneBoundary(frame, leftEgoBoundary, sensor, xVehiclePoints, 'Color','Red');
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, rightEgoBoundary, sensor, xVehiclePoints, 'Color','Green');
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, centerEgoBoundary, sensor, xVehiclePoints, 'Color','Blue');
end

function imageROI = vehicleToImageROI(birdsEyeConfig, vehicleROI)

vehicleROI = double(vehicleROI);

loc2 = abs(vehicleToImage(birdsEyeConfig, [vehicleROI(2) vehicleROI(4)]));
loc1 = abs(vehicleToImage(birdsEyeConfig, [vehicleROI(1) vehicleROI(4)]));
loc4 =     vehicleToImage(birdsEyeConfig, [vehicleROI(1) vehicleROI(4)]);
loc3 =     vehicleToImage(birdsEyeConfig, [vehicleROI(1) vehicleROI(3)]);

[minRoiX, maxRoiX, minRoiY, maxRoiY] = deal(loc4(1), loc3(1), loc2(2), loc1(2));

imageROI = round([minRoiX, maxRoiX, minRoiY, maxRoiY]);

end

function isGood = validateBoundaryFcn(params)

if ~isempty(params)
    a = params(1);
    
    % Reject any curve with a small 'a' coefficient, which makes it highly
    % curved.
    isGood = abs(a) < 0.003; % a from ax^2+bx+c
else
    isGood = false;
end
end

function boundaries = classifyLaneTypes(boundaries, boundaryPoints)

for bInd = 1 : numel(boundaries)
    vehiclePoints = boundaryPoints{bInd};
    % Sort by x
    vehiclePoints = sortrows(vehiclePoints, 1);
    
    xVehicle = vehiclePoints(:,1);
    xVehicleUnique = unique(xVehicle);
    
    % Dashed vs solid
    xdiff  = diff(xVehicleUnique);
    % Sufficiently large threshold to remove spaces between points of a
    % solid line, but not large enough to remove spaces between dashes
    xdifft = mean(xdiff) + 3*std(xdiff);
    largeGaps = xdiff(xdiff > xdifft);
    
    % Safe default
    boundaries(bInd).BoundaryType= LaneBoundaryType.Solid;
    if largeGaps>2
        % Ideally, these gaps should be consistent, but you cannot rely
        % on that unless you know that the ROI extent includes at least 3 dashes.
        boundaries(bInd).BoundaryType = LaneBoundaryType.Dashed;
    end
end

end