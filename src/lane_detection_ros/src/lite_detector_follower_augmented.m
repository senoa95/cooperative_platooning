close all
clear
clc

veh_id = 'trex';
%% initialize camara intrinsics
% focalLength = cameraParams.FocalLength;
% principalPoint = cameraParams.PrincipalPoint;
% imageSize = cameraParams.ImageSize;
focalLength = [637.8722,637.0641];
principalPoint = [323.5977,239.8220];
imageSize      = [480, 640];  
camIntrinsics = cameraIntrinsics(focalLength, principalPoint, imageSize);

%% determine camera sensor placement
height = 0.3;    % mounting height in meters from the ground
pitch  = 0;        % pitch of the camera in degrees
sensor = monoCamera(camIntrinsics, height, 'Pitch', pitch);
%% initialize matlab ros node
rosshutdown
rosinit

rosout_sub = rossubscriber('rosout');

cam_topic = ['/', veh_id, '_cam/image_raw/compressed'];
cam_sub = rossubscriber(cam_topic, 'sensor_msgs/CompressedImage');

centerLaneRawTopic = ['/',veh_id, '/center_lane'];
centerLaneRaw_sub = rossubscriber(centerLaneRawTopic, 'path_follower/lane');

centerLaneAugTopic = ['/',veh_id, '/aug_center_lane'];
centerLaneAug_sub = rossubscriber(centerLaneAugTopic, 'path_follower/lane');

left_lane_topic = ['/',veh_id, '/left_lane'];
left_lane_pub = rospublisher(left_lane_topic,'path_follower/lane');
left_lane_msg = rosmessage(left_lane_pub);

right_lane_topic = ['/',veh_id, '/right_lane'];
right_lane_pub = rospublisher(right_lane_topic,'path_follower/lane');
right_lane_msg = rosmessage(right_lane_pub);

%% Initialize Lane Center Detector Values
Ts = 0.1;
PredictionHorizon = 2;
center_curvature_derivative.Data = 0;
center_curvature.Data = 0;
center_relative_yaw_angle.Data = 0; 
center_lateral_deviation.Data = 0;

%% Main Loop
i = 1;
moveAvWindow = 10;
first = true;
while true
%% subscribe to compressed camera image

msg = cam_sub.receive;
frame = msg.readImage;
rosout = rosout_sub.receive;

centerLaneRawMsg = centerLaneRaw_sub.receive;
centerLaneAugMsg = centerLaneAug_sub.receive;

%% specify lane detection parameters
distAheadOfSensor = 10; % in meters, as previously specified in monoCamera height input
spaceToOneSide    = 4.25;  % all other distance quantities are also in meters
bottomOffset      = 0.01;

outView   = [bottomOffset, distAheadOfSensor, -spaceToOneSide, spaceToOneSide]; % [xmin, xmax, ymin, ymax]
imageSize = [NaN, 640]; % output image width in pixels; height is chosen automatically to preserve units per pixel ratio

%% transform image
birdsEyeConfig = birdsEyeView(sensor, outView, imageSize);

birdsEyeImage = transformImage(birdsEyeConfig, frame);

% Convert to grayscale
birdsEyeImage = rgb2gray(birdsEyeImage);

% Lane marker segmentation ROI in world units
vehicleROI = outView - [0, 0, -0.1, 0.1]; % look 3 meters to left and right, and 4 meters ahead of the sensor
approxLaneMarkerWidthVehicle = 0.2; % centimeters

%% detect lane 
% Detect lane features
laneSensitivity = 0.1;
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
minXLength         = maxPossibleXLength * 0.1; % establish a threshold

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

if first
    leftEgoBoundary       = boundaries(leftEgoBoundaryIndex);
    rightEgoBoundary      = boundaries(rightEgoBoundaryIndex);
    prevLeftEgoBoundary = leftEgoBoundary;
    prevRightEgoBoundary = rightEgoBoundary;
    prevCenterRawEgoBoundary = leftEgoBoundary;
    prevCenterAugEgoBoundary = leftEgoBoundary;
    
    prevLeftEgoBoundary(1).Parameters = [0,0,0,0];
    prevLeftEgoBoundary(1).BoundaryType = 'Solid';
    prevLeftEgoBoundary(1).Strength = 0;
    prevLeftEgoBoundary(1).XExtent = [0, 0];
    prevLeftEgoBoundary(1).Width = 0;

    prevRightEgoBoundary(1).Parameters = [0,0,0,0];
    prevRightEgoBoundary(1).BoundaryType = 'Solid';
    prevRightEgoBoundary(1).Strength = 0;
    prevRightEgoBoundary(1).XExtent = [0, 0];
    prevRightEgoBoundary(1).Width = 0;
    
    prevCenterRawEgoBoundary(1).Parameters = [0,0,0,0];
    prevCenterRawEgoBoundary(1).BoundaryType = 'Solid';
    prevCenterRawEgoBoundary(1).Strength = 0;
    prevCenterRawEgoBoundary(1).XExtent = [0, 0];
    prevCenterRawEgoBoundary(1).Width = 0;

    prevCenterAugEgoBoundary(1).Parameters = [0,0,0,0];
    prevCenterAugEgoBoundary(1).BoundaryType = 'Solid';
    prevCenterAugEgoBoundary(1).Strength = 0;
    prevCenterAugEgoBoundary(1).XExtent = [0, 0];
    prevCenterAugEgoBoundary(1).Width = 0;
    
    first = false;
end

leftEgoBoundary   = boundaries(leftEgoBoundaryIndex);
rightEgoBoundary  = boundaries(rightEgoBoundaryIndex);

if ~isempty(leftEgoBoundary)
    prevLeftEgoBoundary = leftEgoBoundary;
end
if ~isempty(rightEgoBoundary)
    prevRightEgoBoundary = rightEgoBoundary;
end

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
        
        centerEgoBoundaryRaw = rightEgoBoundary; %assign center lane to left lane;
        centerEgoBoundaryAug = rightEgoBoundary;
        
%         pack left lane values with zeros. Set strength to 0.
        disp('left lane not detected')
        left_strength = 0;
        left_curvature_rate = 0;
        left_curvature = 0;
        left_relative_yaw_angle = 0;
        left_lateral_deviation = 0;
    else
%         if both left and right lanes not detected continue
        disp('no lanes detected. continuing')
        [birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,prevLeftEgoBoundary,prevCenterRawEgoBoundary,prevCenterAugEgoBoundary,prevRightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
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
    
    centerEgoBoundaryRaw = leftEgoBoundary; %assign center lane to left lane;
    centerEgoBoundaryAug = leftEgoBoundary;
    
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
        right_strength = 0;
        right_curvature_rate = 0;
        right_curvature = 0;
        right_relative_yaw_angle = 0;
        right_lateral_deviation = 0;
    end
end

right_lane_msg.Strength = right_strength;
right_lane_msg.RhoDot = right_curvature_rate;
right_lane_msg.Rho = right_curvature;
right_lane_msg.Phi = right_relative_yaw_angle;
right_lane_msg.Y = right_lateral_deviation;
send(right_lane_pub, right_lane_msg)


left_lane_msg.Strength = left_strength;
left_lane_msg.RhoDot = left_curvature_rate;
left_lane_msg.Rho = left_curvature;
left_lane_msg.Phi = left_relative_yaw_angle;
left_lane_msg.Y = left_lateral_deviation;
send(left_lane_pub, left_lane_msg)

% 
% right_lane_rho_dot_msg.Data = right_curvature_rate;
% send(right_lane_rho_dot_pub, right_lane_rho_dot_msg)
% right_lane_rho_msg.Data = right_curvature;
% send(right_lane_rho_pub, right_lane_rho_msg)
% right_lane_phi_msg.Data = right_relative_yaw_angle;
% send(right_lane_phi_pub, right_lane_phi_msg)
% right_lane_y_msg.Data = right_lateral_deviation;
% send(right_lane_y_pub, right_lane_y_msg)
% 
% left_lane_rho_dot_msg.Data = left_curvature_rate;
% send(left_lane_rho_dot_pub, left_lane_rho_dot_msg)
% left_lane_rho_msg.Data = left_curvature;
% send(left_lane_rho_pub, left_lane_rho_msg)
% left_lane_phi_msg.Data = left_relative_yaw_angle;
% send(left_lane_phi_pub, left_lane_phi_msg)
% left_lane_y_msg.Phi = left_lateral_deviation;
% send(left_lane_y_pub, left_lane_y_msg.Phi)

%     [birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,leftEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);

% if ~isempty(leftEgoBoundary) || ~isempty(rightEgoBoundary)

% %     sim('estimate_lane_center.slx')

%% Running window filter for center lane - Raw
centerRhoDotRaw(i) = centerLaneRawMsg.RhoDot;
centerRhoRaw(i) = centerLaneRawMsg.Rho;
centerPhiRaw(i) = centerLaneRawMsg.Phi;
centerYRaw(i) = centerLaneRawMsg.Y;

meanRhoDotRaw = movmean(centerRhoDotRaw,moveAvWindow);
meanRhoRaw = movmean(centerRhoRaw,moveAvWindow);
meanPhiRaw = movmean(centerPhiRaw,moveAvWindow);
meanYRaw = movmean(centerYRaw,moveAvWindow);

centerEgoBoundaryRaw.Parameters(1) = meanRhoDotRaw(i);
centerEgoBoundaryRaw.Parameters(2) = meanRhoRaw(i);
centerEgoBoundaryRaw.Parameters(3) = meanPhiRaw(i);
centerEgoBoundaryRaw.Parameters(4) = meanYRaw(i);

%% Running window filter for center lane - Raw
centerRhoDotAug(i) = centerLaneAugMsg.RhoDot;
centerRhoAug(i) = centerLaneAugMsg.Rho;
centerPhiAug(i) = centerLaneAugMsg.Phi;
centerYAug(i) = centerLaneAugMsg.Y;

meanRhoDotAug = movmean(centerRhoDotAug,moveAvWindow);
meanRhoAug = movmean(centerRhoAug,moveAvWindow);
meanPhiAug = movmean(centerPhiAug,moveAvWindow);
meanYAug = movmean(centerYAug,moveAvWindow);

centerEgoBoundaryAug.Parameters(1) = meanRhoDotAug(i);
centerEgoBoundaryAug.Parameters(2) = meanRhoAug(i);
centerEgoBoundaryAug.Parameters(3) = meanPhiAug(i);
centerEgoBoundaryAug.Parameters(4) = meanYAug(i);

%% Display the lanes
prevCenterRawEgoBoundary = centerEgoBoundaryRaw;
prevCenterAugEgoBoundary = centerEgoBoundaryAug;

[birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,centerEgoBoundaryRaw,centerEgoBoundaryAug,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
%     clear centerEgoBoundary
subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
imshow(birdsEyeWithEgoLane)
subplot('Position', [0.5, 0, 0.5, 1.0])
imshow(frameWithEgoLane)
    
% else
%     continue
% end
i = i + 1;
end
%% supporting functions

function [birdsEyeWithEgoLane,frameWithEgoLane] =showLanes(birdsEyeImage,leftEgoBoundary,centerEgoBoundaryRaw,centerEgoBoundaryAug,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor)

xVehiclePoints = bottomOffset:distAheadOfSensor;
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeImage, leftEgoBoundary , birdsEyeConfig, xVehiclePoints, 'Color','Red', 'LineWidth', 7);
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, centerEgoBoundaryRaw, birdsEyeConfig, xVehiclePoints, 'Color','Yellow', 'LineWidth', 7);
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, rightEgoBoundary, birdsEyeConfig, xVehiclePoints, 'Color','Green',  'LineWidth', 10);
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, centerEgoBoundaryAug, birdsEyeConfig, xVehiclePoints, 'Color','Blue', 'LineWidth', 3);

frameWithEgoLane = insertLaneBoundary(frame, leftEgoBoundary, sensor, xVehiclePoints, 'Color','Red',  'LineWidth', 10);
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, rightEgoBoundary, sensor, xVehiclePoints, 'Color','Green',  'LineWidth', 10);
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, centerEgoBoundaryRaw, sensor, xVehiclePoints, 'Color','Yellow',  'LineWidth', 7);
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, centerEgoBoundaryAug, sensor, xVehiclePoints, 'Color','Blue',  'LineWidth', 3);
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