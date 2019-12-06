function [allData, scenario, sensors] = EGO_Lead_Vehicle_Curvature_0_01()
%EGO_Lead_Vehicle_Curvature_0_01 - Returns sensor detections
%    allData = EGO_Lead_Vehicle_Curvature_0_01 returns sensor detections in a structure
%    with time for an internally defined scenario and sensor suite.
%
%    [allData, scenario, sensors] = EGO_Lead_Vehicle_Curvature_0_01 optionally returns
%    the drivingScenario and detection generator objects.

% Generated by MATLAB(R) 9.5 and Automated Driving System Toolbox 1.3.
% Generated on: 08-Dec-2018 02:44:13

% Create the drivingScenario object and ego car
[scenario, egoCar] = createDrivingScenario;

% Create all the sensors
[sensors, numSensors] = createSensors(scenario);

allData = struct('Time', {}, 'ActorPoses', {}, 'ObjectDetections', {}, 'LaneDetections', {});
running = true;
while running
    
    % Generate the target poses of all actors relative to the ego car
    poses = targetPoses(egoCar);
    % Generate the boundaries of all lanes relative to the ego car for 100m
%     lanes = laneBoundaries(egoCar, 'XDistance', 100);
    time  = scenario.SimulationTime;
    
    objectDetections = {};
    laneDetections   = [];
    isValidTime      = false(1, numSensors);
    isValidLaneTime  = false(1, numSensors);
    
    % Generate detections for each sensor
    for sensorIndex = 1:numSensors
        lanes = laneBoundaries(egoCar, 'XDistance', linspace(0, sensors{sensorIndex}.MaxRange, 100));
        type = getDetectorOutput(sensors{sensorIndex});
        if strcmp(type, 'Objects only')
            [objectDets, numObjects, isValidTime(sensorIndex)] = sensors{sensorIndex}(poses, time);
            objectDetections = [objectDetections; objectDets(1:numObjects)]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes only')
            [laneDets, ~, isValidTime(sensorIndex)] = sensors{sensorIndex}(lanes, time);
            laneDetections   = [laneDetections laneDets]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes and objects')
            [objectDets, numObjects, isValidTime(sensorIndex), laneDets, ~, isValidLaneTime(sensorIndex)] = sensors{sensorIndex}(poses, lanes, time);
            objectDetections = [objectDetections; objectDets(1:numObjects)]; %#ok<AGROW>
            laneDetections   = [laneDetections laneDets]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes with occlusion')
            [laneDets, ~, isValidLaneTime(sensorIndex)] = sensors{sensorIndex}(poses, lanes, time);
            laneDetections   = [laneDetections laneDets]; %#ok<AGROW>
        end
    end
    
    % Aggregate all detections into a structure for later use
    if any(isValidTime) || any(isValidLaneTime)
        allData(end + 1) = struct( ...
            'Time',       scenario.SimulationTime, ...
            'ActorPoses', actorPoses(scenario), ...
            'ObjectDetections', {objectDetections}, ...
            'LaneDetections',   {laneDetections}); %#ok<AGROW>
    end
    
    % Advance the scenario one time step and exit the loop if the scenario is complete
    running = advance(scenario);
end

% Restart the driving scenario to return the actors to their initial positions.
restart(scenario);

% Release all the sensor objects so they can be used again.
for sensorIndex = 1:numSensors
    release(sensors{sensorIndex});
end

%%%%%%%%%%%%%%%%%%%%
% Helper functions %
%%%%%%%%%%%%%%%%%%%%

% Units used in createSensors and createDrivingScenario
% Distance/Position - meters
% Speed             - meters/second
% Angles            - degrees
% RCS Pattern       - dBsm

function [sensors, numSensors] = createSensors(scenario)
% createSensors Returns all sensor objects to generate detections

% Assign into each sensor the physical and radar profiles for all actors
profiles = actorProfiles(scenario);
sensors{1} = visionDetectionGenerator('SensorIndex', 1, ...
    'SensorLocation', [5.4 0], ...
    'Height', 2.55, ...
    'Pitch', 0.514, ...
    'DetectionProbability', 0.95, ...
    'MaxSpeed', 83, ...
    'DetectorOutput', 'Lanes with occlusion', ...
    'Intrinsics', cameraIntrinsics([800 800],[320 240],[960 1280]), ...
    'ActorProfiles', profiles);
sensors{2} = radarDetectionGenerator('SensorIndex', 2, ...
    'SensorLocation', [7.2 0], ...
    'MaxRange', 100, ...
    'ActorProfiles', profiles);
numSensors = 2;

function [scenario, egoCar] = createDrivingScenario
% createDrivingScenario Returns the drivingScenario defined in the Designer

% Construct a drivingScenario object.
scenario = drivingScenario('SampleTime', 0.005);

% Add all road segments
roadCenters = [-0.2 96.3 0;
    12.1 95.8 0;
    22.1 94.27 0;
    32.1 91.7 0;
    42.1 87.96 0;
    52.1 82.9 0;
    62.1 76.3 0;
    72.1 67.7 0;
    82.1 56.3 0;
    92.1 39.8 0;
    102.1 -3.7 0;
    102.1 -13.7 0;
    102.1 -100 0];
laneSpecification = lanespec(2);
road(scenario, roadCenters, 'Lanes', laneSpecification);

% Add the ego car
egoCar = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.5, ...
    'Height', 3.5, ...
    'Position', [29.4 90.43 0.01]);
waypoints = [29.4 90.43 0.01;
    41.6 86.4 0;
    51.5 81.5 0;
    61 74.9 0;
    71.3 66.3 0;
    80.9 55.2 0;
    90.5 39.4 0;
    95.3 25.8 0;
    97.33 18.43 0.01;
    99.2 10.1 0;
    100.45 -2.24 0.01;
    100.5 -14.7 0;
    100.14 -99.88 0.01];
speed = 20;
trajectory(egoCar, waypoints, speed);

% Add the non-ego actors
truck = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.5, ...
    'Height', 3.5, ...
    'Position', [5.7 93.6 0]);
waypoints = [5.7 93.6 0;
    14.7 93.6 0;
    21.63 92.34 0.01;
    31.47 89.72 0.01;
    41.39 86.31 0.01;
    51.3 81.5 0;
    60.9 74.9 0;
    70.8 66.7 0;
    81 55.3 0;
    90.8 39.3 0;
    94.9 26.5 0;
    97.1 18.3 0;
    98.9 9.8 0;
    100.5 -3.12 0.01;
    100.44 -13.84 0.01;
    100.3 -99.7 0];
speed = 20;
trajectory(truck, waypoints, speed);

function output = getDetectorOutput(sensor)

if isa(sensor, 'visionDetectionGenerator')
    output = sensor.DetectorOutput;
else
    output = 'Objects only';
end

