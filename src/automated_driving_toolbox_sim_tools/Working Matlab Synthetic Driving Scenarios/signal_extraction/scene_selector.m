function [follower_allData, leader_allData, varargout] = scene_selector(sceneName, ws_DIR)
if strcmp(sceneName, 's')
    if isfile([ws_DIR 'leader_Data_s_curvature.mat'])
        load([ws_DIR 'leader_Data_s_curvature.mat'], 'leader_allData')
    end
    if isfile([ws_DIR 'follower_Data_s_curvature.mat'])
        load([ws_DIR 'follower_Data_s_curvature.mat'], 'follower_allData')
    end
    if isfile([ws_DIR 'follower_alone_s_curvature.mat'])
        load([ws_DIR 'follower_alone_s_curvature.mat'], 'follower_alone_allData')
    end
    if ~exist('follower_allData' ,'var')
        [follower_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_s_curve();
    end
    if ~exist('leader_allData','var')
        [leader_allData, leader_scenario, leader_sensors] = EGO_Lead_Vehicle_s_curve();
    end
    if ~exist('follower_alone_allData' ,'var')
        [follower_alone_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Alone_s_curve();
    end
    varargout{1} = follower_alone_allData;
    
    save([ws_DIR 'leader_Data_s_curvature.mat'],'leader_allData');
    save([ws_DIR 'follower_Data_s_curvature.mat'],'follower_allData');
    save([ws_DIR 'follower_alone_Data_s_curvature.mat'],'follower_alone_allData');
elseif strcmp(sceneName,'left_turn')
    
    if isfile([ws_DIR 'leader_Data_left_turn.mat'])
        load([ws_DIR 'leader_Data_left_turn.mat'], 'leader_allData')
    end
    if isfile([ws_DIR 'follower_Data_left_turn.mat'])
        load([ws_DIR 'follower_Data_left_turn.mat'], 'follower_allData')
    end
    if isfile([ws_DIR 'follower_alone_Data_left_turn.mat'])
        load([ws_DIR 'follower_alone_Data_left_turn.mat'], 'follower_alone_allData')
    end
    if ~exist('follower_allData' ,'var')
        [follower_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Left_Turn();
    end
    if ~exist('leader_allData','var')
        [leader_allData, leader_scenario, leader_sensors] = EGO_Lead_Vehicle_Left_Turn();
    end
    if ~exist('follower_alone_allData' ,'var')
        [follower_alone_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Alone_Left_Turn();
    end
    varargout{1} = follower_alone_allData;
    
    save([ws_DIR 'leader_Data_left_turn.mat'],'leader_allData');
    save([ws_DIR 'follow_Data_left_turn.mat'],'follower_allData');
    save([ws_DIR 'follower_alone_Data_left_turn.mat'],'follower_alone_allData');
    
elseif strcmp(sceneName,'0_0_1')
    if isfile([ws_DIR 'leader_Data_0_0_1_curvature.mat'])
        load([ws_DIR 'leader_Data_0_0_1_curvature.mat'], 'leader_allData')
    end
    if isfile([ws_DIR 'follower_Data_0_0_1_curvature.mat'])
        load([ws_DIR 'follower_Data_0_0_1_curvature.mat'], 'follower_allData')
    end
    
    if isfile([ws_DIR 'follower_alone_Data_0_0_1_curvature.mat'])
        load([ws_DIR 'follower_alone_Data_0_0_1_curvature.mat'], 'follower_alone_allData')
    end
    if ~exist('follower_allData' ,'var')
        [follower_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Curvature_0_01();
    end
    if ~exist('leader_allData','var')
        [leader_allData, leader_scenario, leader_sensors] = EGO_Lead_Vehicle_Curvature_0_01();
    end
    if ~exist('follower_alone_allData','var')
        [follower_alone_allData, leader_scenario, leader_sensors] = EGO_Follow_Vehicle_Alone_Curvature_0_01();
    end
    if isfile([ws_DIR 'follower_alone_Data_0_0_1_curvature.mat'])
        load([ws_DIR 'follower_alone_Data_0_0_1_curvature.mat'], 'follower_alone_allData')
    end
    
    varargout{1} = follower_alone_allData;
    
    save([ws_DIR 'leader_Data_0_0_1_curvature.mat'],'leader_allData');
    save([ws_DIR 'follower_Data_0_0_1_curvature.mat'],'follower_allData');
    save([ws_DIR 'follower_alone_Data_0_0_1_curvature.mat'],'follower_alone_allData');
elseif strcmp(sceneName,'right_turn')
    if isfile([ws_DIR 'leader_Data_right_turn.mat'])
        load([ws_DIR 'leader_Data_right_turn.mat'], 'leader_allData')
    end
    if isfile([ws_DIR 'follower_Data_right_turn.mat'])
        load([ws_DIR 'follower_Data_right_turn.mat'], 'follower_allData')
    end
    if isfile([ws_DIR 'follower_alone_Data_right_turn.mat'])
        load([ws_DIR 'follower_alone_Data_right_turn.mat'], 'follower_alone_allData')
    end
    
    if ~exist('follower_allData' ,'var')
        [follower_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_right_turn();
    end
    if ~exist('leader_allData','var')
        [leader_allData, leader_scenario, leader_sensors] =  EGO_Lead_Vehicle_right_turn();
    end
    if ~exist('follower_alone_allData' ,'var')
        [follower_alone_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Alone_right_turn();
    end
    varargout{1} = follower_alone_allData;
    
    save([ws_DIR 'leader_Data_right_turn.mat'],'leader_allData');
    save([ws_DIR 'follower_Data_right_turn.mat'],'follower_allData');
    save([ws_DIR 'follower_alone_Data_right_turn.mat'],'follower_alone_allData');
    
elseif strcmp(sceneName,'straight')
    
    if isfile([ws_DIR 'leader_Data_straight.mat'])
        load([ws_DIR 'leader_Data_straight.mat'], 'leader_allData')
    end
    if isfile([ws_DIR 'follower_Data_straight.mat'])
        load([ws_DIR 'follower_Data_straight.mat'], 'follower_allData')
    end
    if isfile([ws_DIR 'follower_alone_Data_straight.mat'])
        load([ws_DIR 'follower_alone_Data_straight.mat'], 'follower_alone_allData')
    end
    
    if ~exist('follower_allData' ,'var')
        [follower_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_straight();
    end
    if ~exist('leader_allData','var')
        [leader_allData, leader_scenario, leader_sensors] =  EGO_Lead_Vehicle_straight();
    end
    if ~exist('follower_alone_allData' ,'var')
        [follower_alone_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Alone_straight();
    end
    varargout{1} = follower_alone_allData;
    
    save([ws_DIR 'leader_Data_straight.mat'],'leader_allData');
    save([ws_DIR 'follower_Data_straight.mat'],'follower_allData');
    save([ws_DIR 'follower_alone_Data_straight.mat'],'follower_alone_allData');
    
elseif strcmp(sceneName,'straight_weaving')
    if isfile([ws_DIR 'leader_Data_straight_weaving.mat'])
        load([ws_DIR 'leader_Data_straight_weaving.mat'], 'leader_allData')
    end
    if isfile([ws_DIR 'follower_Data_straight_weaving.mat'])
        load([ws_DIR 'follower_Data_straight_weaving.mat'], 'follower_allData')
    end
    if isfile([ws_DIR 'follower_alone_Data_straight_weaving.mat'])
        load([ws_DIR 'follower_alone_Data_straight_weaving.mat'], 'follower_alone_allData')
    end
    if ~exist('follower_alone_allData' ,'var')
        [follower_alone_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Alone_weaving_straight();
    end
    varargout{1} = follower_alone_allData;
    if ~exist('follower_allData' ,'var')
        [follower_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_weaving_straight();
    end
    if ~exist('leader_allData','var')
        [leader_allData, leader_scenario, leader_sensors] =  EGO_Lead_Vehicle_weaving_straight();
    end
    save([ws_DIR 'leader_Data_straight_weaving.mat'],'leader_allData');
    save([ws_DIR 'follower_Data_straight_weaving.mat'],'follower_allData');
    save([ws_DIR 'follower_alone_Data_straight_weaving.mat'],'follower_alone_allData');
    
elseif strcmp(sceneName,'long_s')
    if isfile([ws_DIR 'leader_Data_long_s.mat'])
        load([ws_DIR 'leader_Data_long_s.mat'], 'leader_allData')
    end
    if isfile([ws_DIR 'follower_Data_long_s.mat'])
        load([ws_DIR 'follower_Data_long_s.mat'], 'follower_allData')
    end
    if isfile([ws_DIR 'follower_alone_long_s.mat'])
        load([ws_DIR 'follower_alone_long_s.mat'], 'follower_alone_allData')
    end
    if ~exist('follower_allData' ,'var')
        [follower_allData, follower_scenario, follower_sensors, followerWayPoints] = EGO_Follow_Vehicle_Long_S();
    else
%         followerWayPoints = follower_allData.followerWayPoints;
    end
    if ~exist('leader_allData','var')
        [leader_allData, leader_scenario, leader_sensors] =  EGO_Lead_Vehicle_Long_S();
    end
    if ~exist('follower_alone_allData' ,'var')
        [follower_alone_allData, follower_scenario, follower_sensors] = EGO_Follow_Vehicle_Alone_Long_S(followerWayPoints);
    end
    varargout{1} = follower_alone_allData;
    
    save([ws_DIR 'leader_Data_long_s.mat'],'leader_allData');
    save([ws_DIR 'follower_Data_long_s.mat'],'follower_allData');
    save([ws_DIR 'follower_alone_Data_long_s.mat'],'follower_alone_allData');
end
end