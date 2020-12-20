close all
clear
clc

lead_veh_id = 'trex2';
follow_veh_id = 'trex';

%% Initialize Lane Center Detector Values
Ts = 0.1;
PredictionHorizon = 2;
% center_curvature_derivative.Data = 0;
% center_curvature.Data = 0;
% center_relative_yaw_angle.Data = 0; 
% center_lateral_deviation.Data = 0;


%% Initialize Ros
lead_left_lane_topic = ['/',lead_veh_id, '/left_lane'];
lead_left_lane_sub = rossubscriber(lead_left_lane_topic);
lead_right_lane_topic = ['/',lead_veh_id, '/right_lane'];
lead_right_lane_sub = rossubscriber(lead_right_lane_topic);

lead_center_lane_topic = ['/',lead_veh_id, '/center_lane'];
lead_center_lane_pub = rospublisher(lead_center_lane_topic,'path_follower/lane');
lead_center_lane_msg = rosmessage(lead_center_lane_pub);

follow_left_lane_topic = ['/',follow_veh_id, '/left_lane'];
follow_left_lane_sub = rossubscriber(follow_left_lane_topic);
follow_right_lane_topic = ['/',follow_veh_id, '/right_lane'];
follow_right_lane_sub = rossubscriber(follow_right_lane_topic);

follow_center_lane_topic = ['/',follow_veh_id, '/center_lane'];
follow_center_lane_pub = rospublisher(follow_center_lane_topic,'path_follower/lane');
follow_center_lane_msg = rosmessage(follow_center_lane_pub);




%% Run center lane compute
while true
    %% parse ros messages
    
    % lead
    lead_left_lane_msg = lead_left_lane_sub.receive;
    lead_right_lane_msg = lead_right_lane_sub.receive;
    
    lead_right_strength = lead_right_lane_msg.Strength;
    lead_right_curvature_rate = lead_right_lane_msg.RhoDot;
    lead_right_curvature = lead_right_lane_msg.Rho;
    lead_right_relative_yaw_angle = lead_right_lane_msg.Phi;
    lead_right_lateral_deviation = lead_right_lane_msg.Y;
    
    lead_left_strength = lead_left_lane_msg.Strength;
    lead_left_curvature_rate = lead_left_lane_msg.RhoDot;
    lead_left_curvature = lead_left_lane_msg.Rho;
    lead_left_relative_yaw_angle = lead_left_lane_msg.Phi;
    lead_left_lateral_deviation = lead_left_lane_msg.Y;
    
    %follow
    follow_left_lane_msg = follow_left_lane_sub.receive;
    follow_right_lane_msg = follow_right_lane_sub.receive;
    
    follow_right_strength = follow_right_lane_msg.Strength;
    follow_right_curvature_rate = follow_right_lane_msg.RhoDot;
    follow_right_curvature = follow_right_lane_msg.Rho;
    follow_right_relative_yaw_angle = follow_right_lane_msg.Phi;
    follow_right_lateral_deviation = follow_right_lane_msg.Y;
    
    follow_left_strength = follow_left_lane_msg.Strength;
    follow_left_curvature_rate = follow_left_lane_msg.RhoDot;
    follow_left_curvature = follow_left_lane_msg.Rho;
    follow_left_relative_yaw_angle = follow_left_lane_msg.Phi;
    follow_left_lateral_deviation = follow_left_lane_msg.Y;
    

    sim('estimate_lane_center.slx')
    leadCenterEgoBoundary.Parameters(1) = mean(lead_center_curvature_derivative.signals.values);
    leadCenterEgoBoundary.Parameters(2) = mean(lead_center_curvature.signals.values(1,:));
    leadCenterEgoBoundary.Parameters(3) = mean(lead_center_relative_yaw_angle.signals.values);
    leadCenterEgoBoundary.Parameters(4) = mean(lead_center_lateral_deviation.signals.values);
    
    followCenterEgoBoundary.Parameters(1) = mean(follow_center_curvature_derivative.signals.values);
    followCenterEgoBoundary.Parameters(2) = mean(follow_center_curvature.signals.values(1,:));
    followCenterEgoBoundary.Parameters(3) = mean(follow_center_relative_yaw_angle.signals.values);
    followCenterEgoBoundary.Parameters(4) = mean(follow_center_lateral_deviation.signals.values);
%     [birdsEyeWithEgoLane,frameWithEgoLane] = showLanes(birdsEyeImage,leftEgoBoundary,centerEgoBoundary,rightEgoBoundary,birdsEyeConfig,bottomOffset,distAheadOfSensor,frame,sensor);

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