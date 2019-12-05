% close all
% clear
% clc

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
if ros.internal.Global.isNodeActive == 0
    rosinit
end

for i = 1:1000000
%% subscribe to compressed camera image
cam_topic = '/usb_cam/image_raw/compressed';
sub = rossubscriber(cam_topic);
msg = sub.receive;
frame = msg.readImage;

%% specify lane detection parameters
distAheadOfSensor = 55; % in meters, as previously specified in monoCamera height input
spaceToOneSide    = 20;  % all other distance quantities are also in meters
bottomOffset      = 0;

outView   = [bottomOffset, distAheadOfSensor, -spaceToOneSide, spaceToOneSide]; % [xmin, xmax, ymin, ymax]
imageSize = [NaN, 250]; % output image width in pixels; height is chosen automatically to preserve units per pixel ratio

%% transform image
birdsEyeConfig = birdsEyeView(sensor, outView, imageSize);

birdsEyeImage = transformImage(birdsEyeConfig, frame);

% Convert to grayscale
birdsEyeImage = rgb2gray(birdsEyeImage);

% Lane marker segmentation ROI in world units
vehicleROI = outView - [0, 0, -0.85, 0.85]; % look 3 meters to left and right, and 4 meters ahead of the sensor
approxLaneMarkerWidthVehicle = 0.1; % 25 centimeters

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


 if size(boundaries,2) == 2

    lanes(1,:) = boundaries(1).Parameters;
    lanes(2,:) = boundaries(2).Parameters;

%         sim('/home/senoa95/Desktop/this_might_track2.slx')
else
    continue
end

%% display left and right lane clothoid parameters

if ~isempty(leftEgoBoundary)
    disp('left lane params')
    disp(leftEgoBoundary.Parameters)
end

if ~isempty(rightEgoBoundary)
    disp('right lane params')
    disp(rightEgoBoundary.Parameters)
end

[birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);
subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
imshow(birdsEyeWithEgoLane)
subplot('Position', [0.5, 0, 0.5, 1.0])
imshow(frameWithEgoLane)

end