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


cam_topic = ['/', veh_id, '_cam/image_raw/compressed'];
cam_sub = rossubscriber(cam_topic, 'sensor_msgs/CompressedImage');

augCenterLaneTopic = '/trex/aug_center_lane';
augCenterLane_sub = rossubscriber(augCenterLaneTopic, 'path_follower/lane');

rawCenterLaneTopic = '/trex/center_lane';
rawCenterLane_sub = rossubscriber(rawCenterLaneTopic, 'path_follower/lane');

left_lane_topic = ['/',veh_id, '/left_lane'];
left_lane_pub = rospublisher(left_lane_topic,'path_follower/lane');
left_lane_msg = rosmessage(left_lane_pub);

right_lane_topic = ['/',veh_id, '/right_lane'];
right_lane_pub = rospublisher(right_lane_topic,'path_follower/lane');
right_lane_msg = rosmessage(right_lane_pub);

%% Initialize Lane Center Detector Values
Ts = 0.1;
PredictionHorizon = 2;

%% Main Loop

while true
%% subscribe to compressed camera image

msg = cam_sub.receive;
frame = msg.readImage;

augCenterLaneMsg = augCenterLane_sub.receive;
rawCenterLaneMsg = rawCenterLane_sub.receive;
%% specify lane detection parameters
distAheadOfSensor = 15; % in meters, as previously specified in monoCamera height input
spaceToOneSide    = 4;  % all other distance quantities are also in meters
bottomOffset      = 0.1;

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

leftEgoBoundary       = boundaries(leftEgoBoundaryIndex);
rightEgoBoundary      = boundaries(rightEgoBoundaryIndex);
%% display left and right lane clothoid parameters

if isempty(leftEgoBoundary)
    if ~isempty(rightEgoBoundary)
        augCenterBoundary = rightEgoBoundary;
        rawCenterBoundary = rightEgoBoundary;
    else
%         if both left and right lanes not detected continue
        disp('no lanes detected. continuing')
        [birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,leftEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
    %     clear centerEgoBoundary
        subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
        imshow(birdsEyeWithEgoLane)
        subplot('Position', [0.5, 0, 0.5, 1.0])
        imshow(frameWithEgoLane)
        continue
    end
else
        augCenterBoundary = leftEgoBoundary;
        rawCenterBoundary = leftEgoBoundary;
    
%   get right lane values
    if ~isempty(rightEgoBoundary)
        augCenterBoundary = leftEgoBoundary;
        rawCenterBoundary = leftEgoBoundary;
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
%%
augCenterBoundary.Parameters = [augCenterLaneMsg.RhoDot,augCenterLaneMsg.Rho,augCenterLaneMsg.Phi,augCenterLaneMsg.Y];
augCenterBoundary.Strength = augCenterLaneMsg.Strength;
rawCenterBoundary.Parameters = [rawCenterLaneMsg.RhoDot,rawCenterLaneMsg.Rho,rawCenterLaneMsg.Phi,rawCenterLaneMsg.Y];
rawCenterBoundary.Strength = rawCenterLaneMsg.Strength;
[birdsEyeWithEgoLane_aug,frameWithEgoLane_aug] = showLanes(birdsEyeImage,augCenterBoundary,augCenterBoundary,rawCenterBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
imshow(birdsEyeWithEgoLane_aug)
subplot('Position', [0.5, 0, 0.5, 1.0])
imshow(frameWithEgoLane_aug)
end
%% supporting functions

function [birdsEyeWithEgoLane,frameWithEgoLane] =showLanes(birdsEyeImage,leftEgoBoundary,centerEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor)

xVehiclePoints = bottomOffset:distAheadOfSensor;
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeImage, leftEgoBoundary , birdsEyeConfig, xVehiclePoints, 'Color','Red', 'LineWidth', 7);
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, centerEgoBoundary, birdsEyeConfig, xVehiclePoints, 'Color','Blue', 'LineWidth', 7);
birdsEyeWithEgoLane = insertLaneBoundary(birdsEyeWithEgoLane, rightEgoBoundary, birdsEyeConfig, xVehiclePoints, 'Color','Green',  'LineWidth', 10);

frameWithEgoLane = insertLaneBoundary(frame, leftEgoBoundary, sensor, xVehiclePoints, 'Color','Red',  'LineWidth', 10);
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, rightEgoBoundary, sensor, xVehiclePoints, 'Color','Green',  'LineWidth', 10);
frameWithEgoLane = insertLaneBoundary(frameWithEgoLane, centerEgoBoundary, sensor, xVehiclePoints, 'Color','Blue',  'LineWidth', 10);
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