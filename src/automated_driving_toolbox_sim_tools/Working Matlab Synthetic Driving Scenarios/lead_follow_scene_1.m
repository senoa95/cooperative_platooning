function [allData_leader, allData_follower, scenario, sensors] = lead_follow_scene_1()
%lead_follow_scene_1 - Returns sensor detections
%    allData = lead_follow_scene_1 returns sensor detections in a structure
%    with time for an internally defined scenario and sensor suite.
%
%    [allData, scenario, sensors] = lead_follow_scene_1 optionally returns
%    the drivingScenario and detection generator objects.

% Generated by MATLAB(R) 9.5 and Automated Driving System Toolbox 1.3.
% Generated on: 13-Nov-2018 22:31:14

% Create the drivingScenario object and ego car
[scenario, leadVehicle, followVehicle] = createDrivingScenario;

% Create all the sensors
[sensors, numSensors] = createSensors(scenario);

allData_leader = struct('Time', {}, 'ActorPoses', {}, 'ObjectDetections', {}, 'LaneDetections', {});
allData_follower = struct('Time', {}, 'ActorPoses', {}, 'ObjectDetections', {}, 'LaneDetections', {});
running = true;
while running
    
    % Generate the target poses of all actors relative to the ego car
    leaderPoses = targetPoses(leadVehicle);
%     disp(leadVehicle.Position)
    followerPoses = targetPoses(followVehicle);
    % Generate the boundaries of all lanes relative to the ego car for 100m
%     leaderLanes = laneBoundaries(leadVehicle, 'XDistance', 100);
%     followerLanes = laneBoundaries(followVehicle, 'XDistance', 100);
    time  = scenario.SimulationTime;
    
    leaderObjectDetections = {};
    followerObjectDetections = {};    
    leaderLaneDetections   = [];
    followerLaneDetections = [];
    isValidTime_leader      = false(1, numSensors);
    isValidLaneTime_leader  = false(1, numSensors);
    
    isValidTime_follower      = false(1, numSensors);
    isValidLaneTime_follower = false(1, numSensors);
    
    % Generate detections for each sensor
    for sensorIndex = 1:numSensors
        type = getDetectorOutput(sensors{sensorIndex});
        leaderLanes = laneBoundaries(leadVehicle, 'XDistance', linspace(0, sensors{sensorIndex}.MaxRange, 100));
        followerLanes = laneBoundaries(followVehicle, 'XDistance',  linspace(0, sensors{sensorIndex}.MaxRange,100));
        if strcmp(type, 'Objects only')
            [leaderObjectDets, leaderNumObjects, isValidTime_leader(sensorIndex)] = sensors{sensorIndex}(leaderPoses, time);
            [followerObjectDets, followerNumObjects, isValidTime_leader(sensorIndex)] = sensors{sensorIndex}(followerPoses, time);
            leaderObjectDetections = [leaderObjectDetections; leaderObjectDets(1:leaderNumObjects)]; %#ok<AGROW>
            followerObjectDetections = [followerObjectDetections; followerObjectDets(1:followerNumObjects)]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes only')
            [leaderLaneDets, ~, isValidTime_leader(sensorIndex)] = sensors{sensorIndex}(leaderLanes, time);
            leaderLaneDetections   = [leaderLaneDetections leaderLaneDets]; %#ok<AGROW>
            %%
            [followerLaneDets, ~, isValidTime_leader(sensorIndex)] = sensors{sensorIndex}(followerLanes, time);
            followerLaneDetections   = [followerLaneDetections followerLaneDets]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes and objects')
            [leaderObjectDets, leaderNumObjects, isValidTime_leader(sensorIndex), leaderLaneDets, ~, isValidLaneTime_leader(sensorIndex)] = sensors{sensorIndex}(leaderPoses, leaderLanes, time);
            leaderObjectDetections = [leaderObjectDetections; leaderObjectDets(1:leaderNumObjects)]; %#ok<AGROW>
            leaderLaneDetections   = [leaderLaneDetections leaderLaneDets]; %#ok<AGROW>
            
            [followerObjectDets, followerNumObjects, isValidTime_leader(sensorIndex), followerLaneDets, ~, isValidLaneTime_leader(sensorIndex)] = sensors{sensorIndex}(followerPoses, followerLanes, time);
            followerObjectDetections = [followerObjectDetections; followerObjectDets(1:followerNumObjects)]; %#ok<AGROW>
            followerLaneDetections   = [followerLaneDetections followerLaneDets]; %#ok<AGROW>
        elseif strcmp(type, 'Lanes with occlusion')
            [leaderLaneDets, ~, isValidLaneTime_leader(sensorIndex)] = sensors{sensorIndex}(leaderPoses, leaderLanes, time);
            leaderLaneDetections   = [leaderLaneDetections leaderLaneDets]; %#ok<AGROW>

            [followerLaneDets, ~, isValidLaneTime_follower(sensorIndex)] = sensors{sensorIndex}(followerPoses, followerLanes, time);
            followerLaneDetections   = [followerLaneDetections followerLaneDets]; %#ok<AGROW>
        end
    end
    
    % Aggregate all detections into a structure for later use
    if any(isValidTime_leader) || any(isValidLaneTime_leader)
        allData_leader(end + 1) = struct( ...
            'Time',       scenario.SimulationTime, ...
            'ActorPoses', actorPoses(scenario), ...
            'ObjectDetections', {leaderObjectDetections}, ...
            'LaneDetections',   {leaderLaneDetections}); %#ok<AGROW>
    end
    
    if any(isValidTime_follower) || any(isValidLaneTime_follower)
        allData_follower(end + 1) = struct( ...
            'Time',       scenario.SimulationTime, ...
            'ActorPoses', actorPoses(scenario), ...
            'ObjectDetections', {followerObjectDetections}, ...
            'LaneDetections',   {followerLaneDetections}); %#ok<AGROW>
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
    'UpdateInterval', 0.05, ...
    'SensorLocation', [5.4 0], ...
    'DetectorOutput', 'Lanes with occlusion', ...
    'Intrinsics', cameraIntrinsics([1600 800],[320 240],[960 1280]), ...
    'ActorProfiles', profiles);
sensors{2} = radarDetectionGenerator('SensorIndex', 2, ...
    'SensorLocation', [7.2 0], ...
    'MaxRange', 100, ...
    'ActorProfiles', profiles);
numSensors = 2;

function [scenario, leadVehicle, followVehicle] = createDrivingScenario(varargin)
% createDrivingScenario Returns the drivingScenario defined in the Designer

% Construct a drivingScenario object.
scenario = drivingScenario;

% Add all road segments
roadCenters = [166.1 87.7 0;
    108.6 55.5 0;
    79.21 53.78 0;
    64.44 51.97 0;
    40.01 43.78 0;
    11.31 23.98 0;
    -11.69 -13.52 0];
laneSpecification = lanespec(2);
road(scenario, roadCenters, 'Lanes', laneSpecification);

% Add the ego car
leadVehicle = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.6, ...
    'Height', 3.5, ...
    'Position', [-8.23 -9.98 0.01]);

waypoints_leader= [4.05 10.74 0.01;
    12.31 21.97 0.01;
    24 31.8 0;
    31.91 37.41 0.01;
    38.6 41.3 0;
    46.83 44.9 0.01;
    57.2 48.3 0;
    70.48 51.28 0.01;
    91.64 52.21 0.01;
    109.61 53.87 0.01;
    136.91 64.36 0.01;
    166.48 85.41 0.01];
speed_leader = 20;
trajectory(leadVehicle, waypoints_leader, speed_leader);

% Add the non-ego actors
followVehicle = vehicle(scenario, ...
    'ClassID', 2, ...
    'Length', 8.2, ...
    'Width', 2.6, ...
    'Height', 3.5, ...
    'Position', [4.05 10.74 0.01]);


waypoints_follower= [-8.23 -9.98 0.01;
    -1.41 2.3 0;
    12.39 22.05 0.01;
    24.01 31.86 0.01;
    31.9 37.4 0;
    38.56 41.27 0.01;
    46.9 45 0;
    57.3 48.4 0;
    70.5 51.3 0;
    91.62 52.19 0.01;
    109.72 53.84 0.01;
    136.83 64.36 0.01;
    166.4 85.5 0.01];
speed_follower = 20;
trajectory(followVehicle, waypoints_follower, speed_follower);

function output = getDetectorOutput(sensor)

if isa(sensor, 'visionDetectionGenerator')
    output = sensor.DetectorOutput;
%     output = 'Lanes only';
else
    output = 'Objects only';
end


