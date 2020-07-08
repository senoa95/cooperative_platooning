close all
clear
clc

lead_veh_id = 'trex2';
follow_veh_id = 'trex';

%% Initialize Lane Center Detector Values
Ts = 0.1;
PredictionHorizon = 2;

%% Initialize Ros
lead_center_lane_topic = ['/',lead_veh_id, '/center_lane'];
lead_center_lane_sub = rossubscriber(lead_center_lane_topic);

lead_inspva_topic = ['/',lead_veh_id, '/inspva'];
lead_inspva_sub = rossubscriber(lead_inspva_topic);

lead_fix_topic = ['/',lead_veh_id, '/fix'];
lead_fix_sub = rossubscriber(lead_fix_topic);

follow_center_lane_topic = ['/',follow_veh_id, '/center_lane'];
follow_center_lane_sub = rossubscriber(follow_center_lane_topic);

follow_inspva_topic = ['/',follow_veh_id, '/inspva'];
follow_inspva_sub = rossubscriber(follow_inspva_topic);

follow_fix_topic = ['/',follow_veh_id, '/fix'];
follow_fix_sub = rossubscriber(follow_fix_topic);


%% Run center lane compute
while true
    %% parse ros messages
    
    % lead
    lead_center_lane_msg = lead_center_lane_sub.receive;
    lead_inspva_msg = lead_inspva_sub.receive;
    lead_fix_msg = lead_fix_sub.receive;
    
    % Follow
    follow_center_lane_msg = follow_center_lane_sub.receive;
    follow_inspva_msg = follow_inspva_sub.receive;
    follow_fix_msg = follow_fix_sub.receive;
    
    %% Convert fix to utm
    lead_pos = deg2utm(lead_fix_msg.Latitude, lead_fix_msg.Longitude);
    follow_pos = deg2utm(follow_fix_msg.Latitude, follow_fix_msg.Longitude);
    
    %% Publish Center Lane Params

    lead_center_lane_msg.Strength = lead_right_strength;
    lead_center_lane_msg.RhoDot = leadCenterEgoBoundary.Parameters(1);
    lead_center_lane_msg.Rho = leadCenterEgoBoundary.Parameters(2);
    lead_center_lane_msg.Phi = leadCenterEgoBoundary.Parameters(3);
    lead_center_lane_msg.Y = leadCenterEgoBoundary.Parameters(4);
    send(lead_center_lane_pub, lead_center_lane_msg)

    follow_center_lane_msg.Strength = follow_right_strength;
    follow_center_lane_msg.RhoDot = followCenterEgoBoundary.Parameters(1);
    follow_center_lane_msg.Rho = followCenterEgoBoundary.Parameters(2);
    follow_center_lane_msg.Phi = followCenterEgoBoundary.Parameters(3);
    follow_center_lane_msg.Y = followCenterEgoBoundary.Parameters(4);
    send(follow_center_lane_pub, follow_center_lane_msg)
%     subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
%     imshow(birdsEyeWithEgoLane)
%     subplot('Position', [0.5, 0, 0.5, 1.0])
%     imshow(frameWithEgoLane)
end