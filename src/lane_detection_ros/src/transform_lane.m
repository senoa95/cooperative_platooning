close all
clear
clc

lead_veh_id = 'trex2';
follow_veh_id = 'trex';

i = 1;
maxDistToAugment = 2;
plotPose = false;
%% Initialize Lane Center Detector Values
Ts = 0.1;
PredictionHorizon = 2;
lead_lane_struct = struct();
follow_lane_struct = struct();
%% Initialize Ros

if ros.internal.Global.isNodeActive == 0
    rosinit
end

pause(0.5)

rosout_sub = rossubscriber('rosout');

lead_center_lane_topic = ['/',lead_veh_id, '/center_lane'];
lead_center_lane_sub = rossubscriber(lead_center_lane_topic, 'path_follower/lane');

lead_inspva_topic = ['/',lead_veh_id, '/inspva'];
lead_inspva_sub = rossubscriber(lead_inspva_topic,'novatel_gps_msgs/Inspva');

lead_fix_topic = ['/',lead_veh_id, '/fix'];
lead_fix_sub = rossubscriber(lead_fix_topic, 'sensor_msgs/NavSatFix');

follow_center_lane_topic = ['/',follow_veh_id, '/center_lane'];
follow_center_lane_sub = rossubscriber(follow_center_lane_topic, 'path_follower/lane');

follow_inspva_topic = ['/',follow_veh_id, '/inspva'];
follow_inspva_sub = rossubscriber(follow_inspva_topic, 'novatel_gps_msgs/Inspva');

follow_fix_topic = ['/',follow_veh_id, '/fix'];
follow_fix_sub = rossubscriber(follow_fix_topic, 'sensor_msgs/NavSatFix');

follow_cam_topic = ['/', follow_veh_id, '_cam/image_raw/compressed'];
follow_cam_sub = rossubscriber(follow_cam_topic, 'sensor_msgs/CompressedImage');
init_lead_pos_lat = 0;

follow_aug_lane_topic = ['/',follow_veh_id,'/aug_center_lane'];
follow_aug_lane_pub = rospublisher(follow_aug_lane_topic, 'path_follower/lane');
follow_aug_lane = rosmessage(follow_aug_lane_pub);

follow_aug_lane_flag_topic = ['/',follow_veh_id,'/aug_center_lane/flag'];
follow_aug_lane_flag_pub = rospublisher(follow_aug_lane_flag_topic, 'std_msgs/Float32');
follow_aug_lane_flag = rosmessage(follow_aug_lane_flag_pub);

%% Run center lane compute
while true
    %% parse ros messages
    
    % time
    rosout = rosout_sub.receive;
    
    % lead
    lead_center_lane_msg = lead_center_lane_sub.receive;
    lead_inspva_msg = lead_inspva_sub.receive;
    lead_fix_msg = lead_fix_sub.receive;
    
    % Follow
    follow_center_lane_msg = follow_center_lane_sub.receive;
    follow_inspva_msg = follow_inspva_sub.receive;
    follow_fix_msg = follow_fix_sub.receive;
    
    %% Convert fix to utm
    [lead_pos.x, lead_pos.y]  = deg2utm(lead_fix_msg.Latitude, lead_fix_msg.Longitude);
    [follow_pos.x, follow_pos.y]  = deg2utm(follow_fix_msg.Latitude, follow_fix_msg.Longitude);
    
    lead_lane_struct.pos(i) = lead_pos;
    follow_lane_struct.pos(i) = follow_pos;
    lead_lane_struct.lane(i) = lead_center_lane_msg;
    follow_lane_struct.lane(i) = follow_center_lane_msg;
    follow_lane_struct.yaw(i) = follow_inspva_msg.Azimuth;
    
    %% Create augmented modified follower lanes
    [min_dist_to_lead(i), min_dist_index] = min(sqrt(([lead_lane_struct.pos.x] - [follow_lane_struct.pos(i).x]).^2 +...
        ([lead_lane_struct.pos.y] - [follow_lane_struct.pos(i).y]).^2))
    
    if plotPose
        figure(1)
        plot(lead_fix_msg.Longitude, lead_fix_msg.Latitude, 'Marker','o','MarkerFaceColor','red');
        hold on
        plot(follow_fix_msg.Longitude, follow_fix_msg.Latitude, 'Marker','o','MarkerFaceColor','green');
        legend('Lead Vehicle', 'Follow Vehicle')
        xlabel('Longitude')
        ylabel('Latitude')
    end
    
     if min_dist_to_lead(i) <= maxDistToAugment
        num_long = 150;
        follow_lane_struct.augLane(i) = lead_lane_struct.lane(min_dist_index);
        follow_lane_struct.augLane(i).Y = follow_lane_struct.lane(min_dist_index).Y;
        lead_lane_struct.compiledLane.longitudinal = linspace(0,50,num_long);
        rangeIdx = 1;
        longRange = zeros(1,num_long);
        tempLateral = zeros(1,num_long);
        for currRange = lead_lane_struct.compiledLane.longitudinal
            longRange(rangeIdx) = currRange;
            tempLateral(rangeIdx) = compute_lateral(lead_lane_struct.lane(min_dist_index),currRange);
            rangeIdx = rangeIdx + 1;
        end
        deltaYaw = deg2rad(-lead_inspva_msg.Azimuth + follow_inspva_msg.Azimuth);
        rotatedLane = rotateLane(tempLateral,longRange,deltaYaw);
        f = fit(longRange', rotatedLane.lateral', 'poly3');
        follow_lane_struct.augLane(i).Phi = f.p3;
        follow_aug_lane_flag.Data = 1;
        aug_lane_flag(i) = 1;
     else
         follow_lane_struct.augLane(i) = follow_lane_struct.lane(min_dist_index);
         follow_aug_lane_flag.Data = 0;
         aug_lane_flag(i) = 0;
     end
     send(follow_aug_lane_pub, follow_lane_struct.augLane(i))
     send(follow_aug_lane_flag_pub, follow_aug_lane_flag)
     time(i) = rosout.Header.Stamp.seconds;
     
     
        
        %     subplot('Position', [0, 0, 0.5, 1.0]) % [left, bottom, width, height] in normalized units
%     imshow(birdsEyeWithEgoLane)
%     subplot('Position', [0.5, 0, 0.5, 1.0])
%     imshow(frameWithEgoLane)

    i = i + 1;
end



%% Rotation
function  rotatedLane = rotateLane(LeadLaneLateral,LeadLaneLongitudinal,relativeHeading)
rotationMtrx = [cos(relativeHeading) -sin(relativeHeading) ; sin(relativeHeading) cos(relativeHeading)];
rotatedLane_temp= rotationMtrx * [LeadLaneLongitudinal; LeadLaneLateral];
rotatedLane.lateral = rotatedLane_temp(2,:);
rotatedLane.longitudinal = rotatedLane_temp(1,:);
end

function lateral_val = compute_lateral(lane_struct,currRange)
lateral_val = lane_struct.Y + lane_struct.Phi*currRange*(2*pi / 360) + lane_struct.Rho*currRange^2 *(0.5/ 1000)...
                    + lane_struct.RhoDot*currRange^3*(0.16667 / (1000^2));
end