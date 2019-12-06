% plot_values(leader, unifiedStruct)
%%
close all
% clearvars  -except loaded_leader_allData loaded_follower_allData
ws_DIR = 'Y:\My Documents\Truck Pairing\Lateral Control\Simulation Tools\Matlab Scenario Designer\Data\';
%Scene: S-Shape = 's'
%Scene: Right Turn = 'right_turn'
%Scene: Straight = 'straight'
%Scene: Straight with weaving leader = 'straight_weaving'
%Scene: Straight with weaving leader = 'left_turn'
%Scene: 0.01 rad/m curvature = '0_0_1'
%Scene: Long S Curve = 'long_s'
allScenes = {'0_0_1','straight','straight_weaving', 'left_turn', 'right_turn', 's', 'long_s'};
%%
leader = [];
follower = [];
followerAlone = [];
leftLaneAugmented_leadFollowArea = [];
rightLaneAugmented_leadFollowArea = [];
leftLaneRaw_leadFollowArea = [];
rightLaneRaw_leadFollowArea = [];

sceneName = '0_0_1';
% [follower_allData, follower_alone_allData, leader_allData] = scene_selector(sceneName,ws_DIR);
[follower_allData, leader_allData, follower_alone_allData] = scene_selector(sceneName,ws_DIR);


%% Extract lane information for lead and follow vehicles
[followerTimeHeadwayVector, followerDistanceHeadwayVector] = leader_follower_timing(follower_allData,leader_allData);
[followerTimeHeadwayVector_alone, ~] = leader_follower_timing(follower_alone_allData,leader_allData);
distanceThresh = 0.8;
for i_leader = 1:size(leader_allData,2)
    leader.time(i_leader) = leader_allData(i_leader).Time;
    leader.globalOrientation(i_leader) = leader_allData(i_leader).ActorPoses(1);
    %Left Lane
    leader.laneStats.leftLane.headingAngle(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 1).HeadingAngle;
    leader.laneStats.leftLane.curvature(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 1).Curvature;
    leader.laneStats.leftLane.curvatureDerivative(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 1).CurvatureDerivative;
    leader.laneStats.leftLane.distance(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 1).LateralOffset;
    leader.laneStats.leftLane.range(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 1).CurveLength;
    %Right Lane
    leader.laneStats.rightLane.headingAngle(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 2).HeadingAngle;
    leader.laneStats.rightLane.curvature(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 2).Curvature;
    leader.laneStats.rightLane.curvatureDerivative(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 2).CurvatureDerivative;
    leader.laneStats.rightLane.distance(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1,2).LateralOffset;
    leader.laneStats.rightLane.range(i_leader) = leader_allData(i_leader).LaneDetections.LaneBoundaries(1, 1).CurveLength;
    
end

for i_followerAlone = 1:size(follower_alone_allData,2)
    followerAlone.time(i_followerAlone) = follower_alone_allData(i_followerAlone).Time;
    followerAlone.globalOrientation(i_followerAlone) = follower_alone_allData(i_followerAlone).ActorPoses(1);
    %Left Lane
    followerAlone.laneStats.leftLane.headingAngle(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 1).HeadingAngle;
    followerAlone.laneStats.leftLane.curvature(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 1).Curvature;
    followerAlone.laneStats.leftLane.curvatureDerivative(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 1).CurvatureDerivative;
    followerAlone.laneStats.leftLane.distance(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 1).LateralOffset;
    followerAlone.laneStats.leftLane.range(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 1).CurveLength;
    %Right Lane
    followerAlone.laneStats.rightLane.headingAngle(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 2).HeadingAngle;
    followerAlone.laneStats.rightLane.curvature(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 2).Curvature;
    followerAlone.laneStats.rightLane.curvatureDerivative(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 2).CurvatureDerivative;
    followerAlone.laneStats.rightLane.distance(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1,2).LateralOffset;
    followerAlone.laneStats.rightLane.range(i_followerAlone) = follower_alone_allData(i_followerAlone).LaneDetections.LaneBoundaries(1, 2).CurveLength;
end

for i_follower = 1:size(follower_allData,2)
    follower.time(i_follower) = follower_allData(i_follower).Time;
    follower.globalOrientation(i_follower) = follower_allData(i_follower).ActorPoses(1);
    %Left Lane
    follower.laneStats.leftLane.headingAngle(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 1).HeadingAngle;
    follower.laneStats.leftLane.curvature(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 1).Curvature;
    follower.laneStats.leftLane.curvatureDerivative(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 1).CurvatureDerivative;
    follower.laneStats.leftLane.distance(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 1).LateralOffset;
    follower.laneStats.leftLane.range(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 1).CurveLength;
    %Right Lane
    follower.laneStats.rightLane.headingAngle(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 2).HeadingAngle;
    follower.laneStats.rightLane.curvature(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 2).Curvature;
    follower.laneStats.rightLane.curvatureDerivative(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 2).CurvatureDerivative;
    follower.laneStats.rightLane.distance(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1,2).LateralOffset;
    follower.laneStats.rightLane.range(i_follower) = follower_allData(i_follower).LaneDetections.LaneBoundaries(1, 2).CurveLength;
end

% follower.headwayedTime = follower.time -  followerTimeHeadwayVector;
leader.headwayedTime = leader.time + followerTimeHeadwayVector;

%% Populate information packet from lead vehicle
unifiedStruct = unify_signals(leader,follower);
unifiedStruct_followerAlone = unify_signals(leader,followerAlone);

sentCounter = 0;
sent.laneStats.rightLane.sentCurvature = unifiedStruct.laneStats.rightLane.curvature.leaderValues;
sent.laneStats.leftLane.sentCurvature =  unifiedStruct.laneStats.leftLane.curvature.leaderValues;
sent.laneStats.rightLane.sentCurvatureDerivative =  unifiedStruct.laneStats.rightLane.curvatureDerivative.leaderValues;
sent.laneStats.leftLane.sentCurvatureDerivative = unifiedStruct.laneStats.leftLane.curvatureDerivative.leaderValues;
sent.laneStats.rightLane.sentHeadingAngle =  unifiedStruct.laneStats.rightLane.headingAngle.leaderValues;
sent.laneStats.leftLane.sentHeadingAngle =  unifiedStruct.laneStats.leftLane.headingAngle.leaderValues;
sent.laneStats.laneWidth = abs(unifiedStruct.laneStats.leftLane.distance.leaderValues) +...
    abs(unifiedStruct.laneStats.rightLane.distance.leaderValues);
sent.laneStats.leftLane.laneRange = unifiedStruct.laneStats.rightLane.range.leaderValues;
sent.laneStats.rightLane.laneRange = unifiedStruct.laneStats.leftLane.range.leaderValues;

%Global Stats
sent.sentGlobalHeading_leader = unifiedStruct.globalOrientation.Yaw.leaderValues;
sent.sentGlobalPosition_leader = unifiedStruct.globalOrientation.Position.leaderValues;

%% Use lane width sent from leader to estimate left and right lane distances
testPose_full = unifiedStruct.globalOrientation.Position.followerValues(:,:) -...
    unifiedStruct.globalOrientation.Position.leaderValues(:,:);
testPose = sqrt(testPose_full(:,1).^2 + testPose_full(:,2).^2);
for mIdx = 1:2
    SigmaRightLane_min = zeros(1,numel(unifiedStruct.timeVec)); % covariance after Propagation
    SigmaLeftLane_min = zeros(1,numel(unifiedStruct.timeVec)); % covariance after Propagation
    SigmaRightLane_plus = zeros(1,numel(unifiedStruct.timeVec)); % covariance after update
    SigmaLeftLane_plus = zeros(1,numel(unifiedStruct.timeVec)); % covariance after update
    for i = 1:numel(follower.time)
        if i > numel(unifiedStruct.timeVec)
            break
        end
%         if i >= 11
%             followerVar_rightLaneDist= nanvar(follower.laneStats.rightLane.distance(1,i-9:i));
%             followerVar_leftLaneDist= nanvar(follower.laneStats.leftLane.distance(1,i-9:i));
%             leaderVar_rightLaneDist = nanvar(leader.laneStats.rightLane.distance(1,i-9:i));
%             leaderVar_leftLaneDist = nanvar(leader.laneStats.leftLane.distance(1,i-9:i));
%         else
%             followerVar_rightLaneDist = nanvar(follower.laneStats.rightLane.distance(1,1:i));
%             followerVar_leftLaneDist = nanvar(follower.laneStats.leftLane.distance(1,1:i));
%             leaderVar_rightLaneDist = nanvar(leader.laneStats.rightLane.distance(1,1:i));
%             leaderVar_leftLaneDist = nanvar(leader.laneStats.leftLane.distance(1,1:i));
%         end
%         
%         if followerVar_rightLaneDist == 0
%             followerVar_rightLaneDist = nan;
%         end
%         if followerVar_leftLaneDist == 0
%             followerVar_leftLaneDist = nan;
%         end
%         if leaderVar_rightLaneDist == 0
%             leaderVar_rightLaneDist = nan;
%         end
%         if leaderVar_leftLaneDist == 0
%             leaderVar_leftLaneDist = nan;
%         end
%         
%         
%         if i >= 10
%             sigmaMeasured_rightLane = std(unifiedStruct.laneStats.rightLane.headingAngle.followerValues(i - 9:i));
%         else
%             sigmaMeasured_rightLane = std(unifiedStruct.laneStats.rightLane.headingAngle.followerValues(1:i));
%         end
%         sigmaMeasured_rightLane = 0.2;
%         
%         if i >= 10
%             sigmaMeasured_leftLane = std(unifiedStruct.laneStats.leftLane.headingAngle.followerValues(i - 9:i));
%         else
%             sigmaMeasured_leftLane = std(unifiedStruct.laneStats.leftLane.headingAngle.followerValues(1:i));
%         end
%         sigmaMeasured_leftLane = 0.2;
%         
%         longTransfVar = 0.1;
%         if followerVar_leftLaneDist > followerVar_rightLaneDist 
%             rightLaneMeasVar = 0.1;
%             leftLaneMeasVar = 0.3;
%             if testPose(i) < distanceThresh
%                 usableDist_rightLaneDist(i) = follower.laneStats.rightLane.distance(i);
%                 [usableDist_leftLaneDistEst(i), SigmaLeftLane_min]  =...
%                     distEstimate_propagate(sent.laneStats.laneWidth(i), SigmaLeftLane_plus, -usableDist_rightLaneDist(i), leftLaneMeasVar);
%                 [usableDist_leftLaneDist(i), SigmaLeftLane_plus] =...
%                     KF_update(usableDist_leftLaneDistEst(i), SigmaLeftLane_min, follower.laneStats.leftLane.distance(i), rightLaneMeasVar);
%                 %             usableDist_leftLaneDist(i) = sent.laneStats.laneWidth(i) + usableDist_rightLaneDist(i);
%             else
%                 usableDist_rightLaneDist(i) = unifiedStruct.laneStats.rightLane.distance.followerValues(i);
%                 usableDist_leftLaneDist(i) = unifiedStruct.laneStats.leftLane.distance.followerValues(i);
%             end
%         elseif followerVar_rightLaneDist < followerVar_leftLaneDist 
%             rightLaneMeasVar = 0.3;
%             leftLaneMeasVar = 0.1;
%             if testPose(i) < distanceThresh
%                 usableDist_leftLaneDist(i) = follower.laneStats.leftLane.distance(i);
%                 [usableDist_rightLaneDistEst(i), SigmaRightLane_min]  =...
%                     distEstimate_propagate(sent.laneStats.laneWidth(i), SigmaRightLane_plus, usableDist_leftLaneDist(i), leftLaneMeasVar);
%                 usableDist_rightLaneDistEst(i) = -usableDist_rightLaneDistEst(i);
%                 [usableDist_rightLaneDist(i), SigmaRightLane_plus] =...
%                     KF_update(usableDist_rightLaneDistEst(i), SigmaRightLane_min, follower.laneStats.rightLane.distance(i), rightLaneMeasVar);
%                 %             usableDist_rightLaneDist(i) = -(sent.laneStats.laneWidth(i) - usableDist_leftLaneDist(i));
%             else
%                 usableDist_rightLaneDist(i) = unifiedStruct.laneStats.rightLane.distance.followerValues(i);
%                 usableDist_leftLaneDist(i) = unifiedStruct.laneStats.leftLane.distance.followerValues(i);
%             end
%             usableDist_rightLaneDist(i) = unifiedStruct.laneStats.rightLane.distance.followerValues(i);
%             usableDist_leftLaneDist(i) = unifiedStruct.laneStats.leftLane.distance.followerValues(i);
%         end
        usableDist_rightLaneDist(i) = unifiedStruct.laneStats.rightLane.distance.followerValues(i);
        usableDist_leftLaneDist(i) = unifiedStruct.laneStats.leftLane.distance.followerValues(i);
    end
end

% figure
% hold on
% plot(follower.headwayedTime(1:sentCounter), mahalD)
% plot(follower.headwayedTime(1:sentCounter), mahalD)


%% Estimate the headingAngle to left and right lanes of follower
%using global and local heading from lead vehicle. The difference of the
%global heading of lead and follow is equal to the difference of the
%heading angle to the same lane when accounting for longitudinal headway.

% relativeHeading = sent.sentGlobalHeading_leader - unifiedStruct.globalOrientation.Yaw.followerValues;
relativeHeading = -unifiedStruct.globalOrientation.Yaw.leaderValues + unifiedStruct.globalOrientation.Yaw.followerValues;
% relativeHeading = deg2rad(relativeHeading);
sizeTemp = numel(relativeHeading);
cosRelHeading = cos(relativeHeading(1:sizeTemp - 1));
corrDistLeftLane = sqrt(unifiedStruct.laneStats.leftLane.distance.followerValues.^2 + unifiedStruct.laneStats.leftLane.distance.leaderValues.^2 - ...
    2*unifiedStruct.laneStats.leftLane.distance.followerValues.*unifiedStruct.laneStats.leftLane.distance.leaderValues.*-cosRelHeading);

corrDistRightLane = sqrt(unifiedStruct.laneStats.rightLane.distance.followerValues.^2 + unifiedStruct.laneStats.rightLane.distance.leaderValues.^2 - ...
    2*unifiedStruct.laneStats.rightLane.distance.followerValues.*unifiedStruct.laneStats.rightLane.distance.leaderValues.*cosRelHeading);

SigmaRightLane_min = zeros(1,numel(unifiedStruct.timeVec)); % covariance after Propagation
SigmaLeftLane_min = zeros(1,numel(unifiedStruct.timeVec)); % covariance after Propagation
SigmaRightLane_plus = zeros(1,numel(unifiedStruct.timeVec)); % covariance after update
SigmaLeftLane_plus = zeros(1,numel(unifiedStruct.timeVec)); % covariance after update

for i = 1:numel(follower.time)
    if i > numel(unifiedStruct.timeVec)
        break
    end
%     if testPose(i) < distanceThresh
        sigmaRelHeading = 0;
        rightLaneHeadingAngleMeasurement = unifiedStruct.laneStats.rightLane.headingAngle.followerValues(i);
        leftLaneHeadingAngleMeasurement = unifiedStruct.laneStats.leftLane.headingAngle.followerValues(i);
        
        if i >= 10
            sigmaMeasured_rightLane = std(unifiedStruct.laneStats.rightLane.headingAngle.followerValues(i - 9:i));
            sigmaMeasured_rightLane = 0.3;
        else
            sigmaMeasured_rightLane = std(unifiedStruct.laneStats.rightLane.headingAngle.followerValues(1:i));
            sigmaMeasured_rightLane = 0.3;
        end
            sigma_measured = 100;
%         [rightLaneHeadingAngle_followerEst(i), SigmaRightLane_min]  =...
%             yawEstimate_propagate(sent.laneStats.rightLane.sentHeadingAngle(i), SigmaRightLane_plus, measuredRelativeHeading(i), sigmaRelHeading);
%         
%         [rightLaneHeadingAngle_followerCorr(i), SigmaRightLane_plus] =...
%             KF_update(rightLaneHeadingAngle_followerEst(i), SigmaRightLane_min, rightLaneHeadingAngleMeasurement, sigma_measured);
        
% function [laneHeadingAngleEst, Sigma_min]  = yawEstimate_propagate(sentHeadingAngle, Sigma_plus, relativeHeading, sigma_relativeHeading)
% laneHeadingAngleEst = sentHeadingAngle + relativeHeading ;
% %  laneHeadingAngleEst = atan(tan(sentHeadingAngle) - tan(relativeHeading)) ;
% Sigma_min = Sigma_plus + sigma_relativeHeading^2;
% end
% 
% function [distFromLaneEst, Sigma_min]  = distEstimate_propagate(laneWidth, Sigma_plus, usableDist, sigma_u)
% distFromLaneEst = laneWidth - usableDist;
% Sigma_min = Sigma_plus + sigma_u^2;
% end


%         rightLaneHeadingAngle_followerCorr(i) = sent.laneStats.rightLane.sentHeadingAngle(i) + measuredRelativeHeading(i);
%         delTemp = sent.laneStats.rightLane.
        
        if i >= 10
            sigmaMeasured_leftLane = var(unifiedStruct.laneStats.leftLane.headingAngle.followerValues(i - 9:i));
        else
            sigmaMeasured_leftLane = var(unifiedStruct.laneStats.leftLane.headingAngle.followerValues(1:i));
        end
        sigmaMeasured_leftLane = 0.3;
        
%         [leftLaneHeadingAngle_followerEst(i), SigmaLeftLane_min]  =...
%             yawEstimate_propagate(sent.laneStats.leftLane.sentHeadingAngle(i), SigmaLeftLane_plus, measuredRelativeHeading(i), sigmaRelHeading);
%         
%         [leftLaneHeadingAngle_followerCorr(i), SigmaLeftLane_plus] =...
%             KF_update(leftLaneHeadingAngle_followerEst(i), SigmaLeftLane_min, leftLaneHeadingAngleMeasurement, sigma_measured);
        
        if  sent.sentGlobalHeading_leader(i) - unifiedStruct.globalOrientation.Yaw.followerValues(i) > 0
            corrDistLeftLane = -corrDistLeftLane;
            corrDistRightLane = -corrDistRightLane;
        elseif  sent.sentGlobalHeading_leader(i) - unifiedStruct.globalOrientation.Yaw.followerValues(i) < 0
            corrDistLeftLane = -corrDistLeftLane;
            corrDistRightLane = -corrDistRightLane;
        else 
            corrDistLeftLane = 0;
            corrDistRightLane = 0;
        end

        rightLaneHeadingAngle_followerCorr(i) = sent.laneStats.rightLane.sentHeadingAngle(i) +...
                sent.sentGlobalHeading_leader(i) - unifiedStruct.globalOrientation.Yaw.followerValues(i);% +...
% (sent.laneStats.rightLane.sentCurvature(i)*corrDistLeftLane(i) + 0.5*sent.laneStats.rightLane.sentCurvatureDerivative(i)*corrDistRightLane(i)^2);  
          
        leftLaneHeadingAngle_followerCorr(i) = sent.laneStats.leftLane.sentHeadingAngle(i) + ...
            unifiedStruct.globalOrientation.Yaw.leaderValues(i) - unifiedStruct.globalOrientation.Yaw.followerValues(i);% + ...
% (sent.laneStats.leftLane.sentCurvature(i)*corrDistLeftLane(i) - 0.5*sent.laneStats.leftLane.sentCurvatureDerivative(i)*corrDistLeftLane(i)^2);
        
%         rightLaneHeadingAngle_followerCorr(i) = -relativeHeading(i) + sent.laneStats.rightLane.sentHeadingAngle(i);% +...
%             sent.laneStats.rightLane.sentCurvature(i)*corrDistLeftLane(i) - 0.5*sent.laneStats.rightLane.sentCurvatureDerivative(i)*corrDistRightLane(i)^2 ;
%         leftLaneHeadingAngle_followerCorr(i) = -relativeHeading(i) + sent.laneStats.leftLane.sentHeadingAngle(i);% +...
%             sent.laneStats.leftLane.sentCurvature(i)*corrDistLeftLane(i) + 0.5*sent.laneStats.leftLane.sentCurvatureDerivative(i)*corrDistLeftLane(i)^2 ;
%     else
%         rightLaneHeadingAngle_followerEst(i) = unifiedStruct.laneStats.rightLane.headingAngle.followerValues(i);
%         leftLaneHeadingAngle_followerEst(i)  = unifiedStruct.laneStats.leftLane.headingAngle.followerValues(i);
    end
% end


figure; hold on
plot(allTime,  unifiedStruct_followerAlone.laneStats.leftLane.headingAngle.followerValues(1:timeSteps))
plot(allTime, leftLaneHeadingAngle_followerCorr)
plot(allTime, relativeHeading(1:timeSteps), 'r--')
title('Left Lane')
figure; hold on
plot(allTime,  unifiedStruct_followerAlone.laneStats.rightLane.headingAngle.followerValues(1:timeSteps))
plot(allTime, rightLaneHeadingAngle_followerCorr)
plot(allTime, relativeHeading(1:timeSteps), 'r--')
title('Right  Lane')
figure; hold on
plot(allTime, unifiedStruct.laneStats.rightLane.headingAngle.followerValues(1:timeSteps) - rightLaneHeadingAngle_followerCorr(1:timeSteps)')
title('Right  Lane')
%% Plot lane estimations
figure
xlim([-4,4])
set(gca, 'XDir','reverse')
grid on
xlabel('Lateral Lane Position (m)')
ylabel('Longitudinal Lane Position (m)')
a = [];b = []; cAug = []; dAug = [];ann = [];cRaw = [];dRaw = [];cAlone = []; dAlone = [];

leaderLaneParams.rightLane.curvatureDerivative =...
    unifiedStruct.laneStats.rightLane.curvatureDerivative.leaderValues;
leaderLaneParams.rightLane.curvature =...
    unifiedStruct.laneStats.rightLane.curvature.leaderValues;
leaderLaneParams.rightLane.distance =...
    unifiedStruct.laneStats.rightLane.distance.leaderValues;
leaderLaneParams.rightLane.headingAngle =...
    unifiedStruct.laneStats.rightLane.headingAngle.leaderValues;
leaderLaneParams.rightLane.range =...
    unifiedStruct.laneStats.rightLane.range.leaderValues;


leaderLaneParams.leftLane.curvatureDerivative =...
    unifiedStruct.laneStats.leftLane.curvatureDerivative.leaderValues;
leaderLaneParams.leftLane.curvature =...
    unifiedStruct.laneStats.leftLane.curvature.leaderValues;
leaderLaneParams.leftLane.distance =...
    unifiedStruct.laneStats.leftLane.distance.leaderValues;
leaderLaneParams.leftLane.headingAngle =...
    unifiedStruct.laneStats.leftLane.headingAngle.leaderValues;
leaderLaneParams.leftLane.range =...
    unifiedStruct.laneStats.leftLane.range.leaderValues;

followerLaneParamsAugmented.rightLane.curvatureDerivative = sent.laneStats.rightLane.sentCurvatureDerivative;
%             unifiedStruct.laneStats.rightLane.curvatureDerivative.followerValues;
followerLaneParamsAugmented.rightLane.curvature = sent.laneStats.rightLane.sentCurvature;
%             unifiedStruct.laneStats.rightLane.curvature.followerValues;
followerLaneParamsAugmented.rightLane.distance = usableDist_rightLaneDist';
%             unifiedStruct.laneStats.rightLane.distance.followerValues;
followerLaneParamsAugmented.rightLane.headingAngle = rightLaneHeadingAngle_followerCorr';
%             unifiedStruct.laneStats.rightLane.headingAngle.followerValues;
followerLaneParamsAugmented.rightLane.range = sent.laneStats.rightLane.laneRange;
%             unifiedStruct.laneStats.rightLane.range.followerValues + sent.laneStats.rightLane.laneRange;

followerAloneLaneParams.rightLane.curvatureDerivative =...
    unifiedStruct_followerAlone.laneStats.rightLane.curvatureDerivative.followerValues;
followerAloneLaneParams.rightLane.curvature =...
    unifiedStruct_followerAlone.laneStats.rightLane.curvature.followerValues;
followerAloneLaneParams.rightLane.distance =...
    unifiedStruct_followerAlone.laneStats.rightLane.distance.followerValues;
followerAloneLaneParams.rightLane.headingAngle =...
    unifiedStruct_followerAlone.laneStats.rightLane.headingAngle.followerValues;
followerAloneLaneParams.rightLane.range = sent.laneStats.rightLane.laneRange;

followerLaneParamsRaw.rightLane.curvatureDerivative =...
    unifiedStruct.laneStats.rightLane.curvatureDerivative.followerValues;
followerLaneParamsRaw.rightLane.curvature =...
    unifiedStruct.laneStats.rightLane.curvature.followerValues;
followerLaneParamsRaw.rightLane.distance =...
    unifiedStruct.laneStats.rightLane.distance.followerValues;
followerLaneParamsRaw.rightLane.headingAngle =...
    unifiedStruct.laneStats.rightLane.headingAngle.followerValues;
followerLaneParamsRaw.rightLane.range = sent.laneStats.rightLane.laneRange;
%             unifiedStruct.laneStats.rightLane.range.followerValues + sent.laneStats.rightLane.laneRange;

followerLaneParamsAugmented.leftLane.curvatureDerivative =  sent.laneStats.leftLane.sentCurvatureDerivative;
%             unifiedStruct.laneStats.leftLane.curvatureDerivative.followerValues;
followerLaneParamsAugmented.leftLane.curvature =  sent.laneStats.leftLane.sentCurvature;
%             unifiedStruct.laneStats.leftLane.curvature.followerValues;
followerLaneParamsAugmented.leftLane.distance = usableDist_leftLaneDist';
%             unifiedStruct.laneStats.leftLane.distance.followerValues;
followerLaneParamsAugmented.leftLane.headingAngle = leftLaneHeadingAngle_followerCorr';
%             unifiedStruct.laneStats.leftLane.headingAngle.followerValues;
followerLaneParamsAugmented.leftLane.range = sent.laneStats.leftLane.laneRange;
%             unifiedStruct.laneStats.leftLane.range.followerValues + sent.laneStats.leftLane.laneRange;

followerLaneParamsRaw.leftLane.curvatureDerivative =...
    unifiedStruct.laneStats.leftLane.curvatureDerivative.followerValues;
followerLaneParamsRaw.leftLane.curvature =...
    unifiedStruct.laneStats.leftLane.curvature.followerValues;
followerLaneParamsRaw.leftLane.distance =...
    unifiedStruct.laneStats.leftLane.distance.followerValues;
followerLaneParamsRaw.leftLane.headingAngle =...
    unifiedStruct.laneStats.leftLane.headingAngle.followerValues;
followerLaneParamsRaw.leftLane.range = unifiedStruct_followerAlone.laneStats.leftLane.range.followerValues;
%         sent.laneStats.rightLane.laneRange;

followerAloneLaneParams.leftLane.curvatureDerivative =...
    unifiedStruct_followerAlone.laneStats.leftLane.curvatureDerivative.followerValues;
followerAloneLaneParams.leftLane.curvature =...
    unifiedStruct_followerAlone.laneStats.leftLane.curvature.followerValues;
followerAloneLaneParams.leftLane.distance =...
    unifiedStruct_followerAlone.laneStats.leftLane.distance.followerValues;
followerAloneLaneParams.leftLane.headingAngle =...
    unifiedStruct_followerAlone.laneStats.leftLane.headingAngle.followerValues;
followerAloneLaneParams.leftLane.range = unifiedStruct_followerAlone.laneStats.leftLane.range.followerValues;

sent.laneStats.rightLane.laneRange;
%             unifiedStruct.laneStats.leftLane.range.followerValues + sent.laneStats.rightLane.laneRange;



for sampleIdx = 1:numel(unifiedStruct.timeVec)    
    if sampleIdx > numel(unifiedStruct_followerAlone.timeVec) 
        break
    end
    
    allTime = unifiedStruct.timeVec(1:sampleIdx);
    currTime = unifiedStruct.timeVec(sampleIdx);
    delete(a);delete(b);delete(cAug);delete(dAug);delete(ann);delete(cRaw);delete(dRaw);delete(cAlone); delete(dAlone)
    hold on
%     for i = 1
%         leaderLaneParams.rightLane.curvatureDerivative =...
%             unifiedStruct.laneStats.rightLane.curvatureDerivative.leaderValues;
%         leaderLaneParams.rightLane.curvature =...
%             unifiedStruct.laneStats.rightLane.curvature.leaderValues;
%         leaderLaneParams.rightLane.distance =...
%             unifiedStruct.laneStats.rightLane.distance.leaderValues;
%         leaderLaneParams.rightLane.headingAngle =...
%             unifiedStruct.laneStats.rightLane.headingAngle.leaderValues;
%         leaderLaneParams.rightLane.range =...
%             unifiedStruct.laneStats.rightLane.range.leaderValues;
%         
%         
%         leaderLaneParams.leftLane.curvatureDerivative =...
%             unifiedStruct.laneStats.leftLane.curvatureDerivative.leaderValues;
%         leaderLaneParams.leftLane.curvature =...
%             unifiedStruct.laneStats.leftLane.curvature.leaderValues;
%         leaderLaneParams.leftLane.distance =...
%             unifiedStruct.laneStats.leftLane.distance.leaderValues;
%         leaderLaneParams.leftLane.headingAngle =...
%             unifiedStruct.laneStats.leftLane.headingAngle.leaderValues;
%         leaderLaneParams.leftLane.range =...
%             unifiedStruct.laneStats.leftLane.range.leaderValues;
%         
%         followerLaneParamsAugmented.rightLane.curvatureDerivative = sent.laneStats.rightLane.sentCurvatureDerivative;
%         %             unifiedStruct.laneStats.rightLane.curvatureDerivative.followerValues;
%         followerLaneParamsAugmented.rightLane.curvature = sent.laneStats.rightLane.sentCurvature;
%         %             unifiedStruct.laneStats.rightLane.curvature.followerValues;
%         followerLaneParamsAugmented.rightLane.distance = usableDist_rightLaneDist';
%         %             unifiedStruct.laneStats.rightLane.distance.followerValues;
%         followerLaneParamsAugmented.rightLane.headingAngle = rightLaneHeadingAngle_followerCorr';
%         %             unifiedStruct.laneStats.rightLane.headingAngle.followerValues;
%         followerLaneParamsAugmented.rightLane.range = sent.laneStats.rightLane.laneRange;
%         %             unifiedStruct.laneStats.rightLane.range.followerValues + sent.laneStats.rightLane.laneRange;
%         
%         followerAloneLaneParams.rightLane.curvatureDerivative =...
%             unifiedStruct_followerAlone.laneStats.rightLane.curvatureDerivative.followerValues;
%         followerAloneLaneParams.rightLane.curvature =...
%             unifiedStruct_followerAlone.laneStats.rightLane.curvature.followerValues;
%         followerAloneLaneParams.rightLane.distance =...
%             unifiedStruct_followerAlone.laneStats.rightLane.distance.followerValues;
%         followerAloneLaneParams.rightLane.headingAngle =...
%             unifiedStruct_followerAlone.laneStats.rightLane.headingAngle.followerValues;
%         followerAloneLaneParams.rightLane.range = sent.laneStats.rightLane.laneRange;
%         
%         followerLaneParamsRaw.rightLane.curvatureDerivative =...
%             unifiedStruct.laneStats.rightLane.curvatureDerivative.followerValues;
%         followerLaneParamsRaw.rightLane.curvature =...
%             unifiedStruct.laneStats.rightLane.curvature.followerValues;
%         followerLaneParamsRaw.rightLane.distance =...
%             unifiedStruct.laneStats.rightLane.distance.followerValues;
%         followerLaneParamsRaw.rightLane.headingAngle =...
%             unifiedStruct.laneStats.rightLane.headingAngle.followerValues;
%         followerLaneParamsRaw.rightLane.range = sent.laneStats.rightLane.laneRange;
%         %             unifiedStruct.laneStats.rightLane.range.followerValues + sent.laneStats.rightLane.laneRange;
%         
%         followerLaneParamsAugmented.leftLane.curvatureDerivative =  sent.laneStats.leftLane.sentCurvatureDerivative;
%         %             unifiedStruct.laneStats.leftLane.curvatureDerivative.followerValues;
%         followerLaneParamsAugmented.leftLane.curvature =  sent.laneStats.leftLane.sentCurvature;
%         %             unifiedStruct.laneStats.leftLane.curvature.followerValues;
%         followerLaneParamsAugmented.leftLane.distance = usableDist_leftLaneDist';
%         %             unifiedStruct.laneStats.leftLane.distance.followerValues;
%         followerLaneParamsAugmented.leftLane.headingAngle = leftLaneHeadingAngle_followerCorr';
%         %             unifiedStruct.laneStats.leftLane.headingAngle.followerValues;
%         followerLaneParamsAugmented.leftLane.range = sent.laneStats.leftLane.laneRange;
%         %             unifiedStruct.laneStats.leftLane.range.followerValues + sent.laneStats.leftLane.laneRange;
%         
%         followerLaneParamsRaw.leftLane.curvatureDerivative =...
%             unifiedStruct.laneStats.leftLane.curvatureDerivative.followerValues;
%         followerLaneParamsRaw.leftLane.curvature =...
%             unifiedStruct.laneStats.leftLane.curvature.followerValues;
%         followerLaneParamsRaw.leftLane.distance =...
%             unifiedStruct.laneStats.leftLane.distance.followerValues;
%         followerLaneParamsRaw.leftLane.headingAngle =...
%             unifiedStruct.laneStats.leftLane.headingAngle.followerValues;
%         followerLaneParamsRaw.leftLane.range = unifiedStruct_followerAlone.laneStats.leftLane.range.followerValues;
% %         sent.laneStats.rightLane.laneRange;
%         
%         followerAloneLaneParams.leftLane.curvatureDerivative =...
%             unifiedStruct_followerAlone.laneStats.leftLane.curvatureDerivative.followerValues;
%         followerAloneLaneParams.leftLane.curvature =...
%             unifiedStruct_followerAlone.laneStats.leftLane.curvature.followerValues;
%         followerAloneLaneParams.leftLane.distance =...
%             unifiedStruct_followerAlone.laneStats.leftLane.distance.followerValues;
%         followerAloneLaneParams.leftLane.headingAngle =...
%             unifiedStruct_followerAlone.laneStats.leftLane.headingAngle.followerValues;
%         followerAloneLaneParams.leftLane.range = unifiedStruct_followerAlone.laneStats.leftLane.range.followerValues;
%         
%         sent.laneStats.rightLane.laneRange;
%         %             unifiedStruct.laneStats.leftLane.range.followerValues + sent.laneStats.rightLane.laneRange;
%     end
    
    leaderLeftLane = compute_lane(leaderLaneParams.leftLane,sampleIdx);
    ann = annotation('textbox' , [0.8,0.2,0.1,0.06],'String',['CurrTime= ', num2str(currTime)]);
    if ~isempty(leaderLeftLane)
        if leaderLaneParams.leftLane.distance(sampleIdx) > 0
            %             a = plot(leaderLeftLane.lateral,leaderLeftLane.longitudinal + followerDistanceHeadwayVector(sampleIdx),'g');
            a = plot(leaderLeftLane.lateral,leaderLeftLane.longitudinal ,'g');
        end
    end
    leaderRightLane = compute_lane(leaderLaneParams.rightLane,sampleIdx);
    if ~isempty(leaderRightLane)
        if leaderLaneParams.rightLane.distance(sampleIdx) < 0
            %             b = plot(leaderRightLane.lateral,leaderRightLane.longitudinal + followerDistanceHeadwayVector(sampleIdx),'g');
            b = plot(leaderRightLane.lateral,leaderRightLane.longitudinal,'g');
        end
    end
    followerLeftLaneAugmented = compute_lane(followerLaneParamsAugmented.leftLane,sampleIdx);
    if ~isempty(followerLeftLaneAugmented)
        followerLeftLaneAugmented = rotateLane(followerLeftLaneAugmented,relativeHeading(sampleIdx));
        if followerLaneParamsAugmented.leftLane.distance(sampleIdx) > 0
            cAug = plot(followerLeftLaneAugmented.lateral,followerLeftLaneAugmented.longitudinal,'k');
        end
    end
    
    followerRightLaneAugmented = compute_lane(followerLaneParamsAugmented.rightLane,sampleIdx);
    if ~isempty(followerRightLaneAugmented)
        followerRightLaneAugmented = rotateLane(followerRightLaneAugmented,relativeHeading(sampleIdx));
        if followerLaneParamsAugmented.rightLane.distance(sampleIdx) < 0
            dAug = plot(followerRightLaneAugmented.lateral,followerRightLaneAugmented.longitudinal,'k');
        end
    end
    
    followerLeftLaneRaw= compute_lane(followerLaneParamsRaw.leftLane,sampleIdx);
    if ~isempty(followerLeftLaneRaw)
        followerLeftLaneRaw = rotateLane(followerLeftLaneRaw,relativeHeading(sampleIdx));
        if followerLaneParamsAugmented.leftLane.distance(sampleIdx) > 0
            cRaw = plot(followerLeftLaneRaw.lateral,followerLeftLaneRaw.longitudinal,'r');
        end
    end
    
    followerRightLaneRaw= compute_lane(followerLaneParamsRaw.rightLane,sampleIdx);
    if ~isempty(followerRightLaneRaw)
        followerRightLaneRaw = rotateLane(followerRightLaneRaw,relativeHeading(sampleIdx));
        if followerLaneParamsRaw.rightLane.distance(sampleIdx) < 0
            dRaw= plot(followerRightLaneRaw.lateral,followerRightLaneRaw.longitudinal,'r');
        end
    end
    
    followerAloneLeftLane = compute_lane(followerAloneLaneParams.leftLane,sampleIdx);
    if ~isempty(followerAloneLeftLane)
        followerAloneLeftLane = rotateLane(followerAloneLeftLane,relativeHeading(sampleIdx));
        if followerLaneParamsAugmented.leftLane.distance(sampleIdx) > 0
            cAlone = plot(followerAloneLeftLane.lateral,followerAloneLeftLane.longitudinal,'y');
        end
    end
    
    followerAloneRightLane = compute_lane(followerAloneLaneParams.rightLane,sampleIdx);
    if ~isempty(followerAloneRightLane)
        followerAloneRightLane = rotateLane(followerAloneRightLane,relativeHeading(sampleIdx));
        if followerLaneParamsRaw.rightLane.distance(sampleIdx) < 0
            dAlone= plot(followerAloneRightLane.lateral,followerAloneRightLane.longitudinal,'y');
        end
    end
    legend('','Lead Vehicle','','Follow Vehicle Augmented','','Follow Vehicle Raw', '', 'Follow Vehicle Alone', 'Location', 'southwest')
%     pause(0.01)
    
    
    % Analyze
    if isempty(followerLeftLaneAugmented) || isempty(followerRightLaneAugmented) || isempty(followerLeftLaneRaw) 
        leftLaneRaw_leadFollowArea(sampleIdx) = nan;
        leftLaneAugmented_leadFollowArea(sampleIdx) = nan;
        rightLaneRaw_leadFollowArea(sampleIdx) = nan;
        rightLaneAugmented_leadFollowArea(sampleIdx) = nan;
        continue
    end
    
    integralMode = 'noDist';
    
    switch integralMode
        case 'noDist'
            
            %         FOLLOWER
            %Left Lane
            %augmented
            %     followerLeftLaneAugmented_rotated = rotateLane(followerLeftLaneAugmented,relativeHeading);
            followerLeftLaneAugmentedIntegral = trapz(followerLeftLaneAugmented.longitudinal, followerLeftLaneAugmented.lateral - followerLaneParamsAugmented.leftLane.distance(sampleIdx));
            followerLeftLaneAugmentedIntegral_normalized = followerLeftLaneAugmentedIntegral / (followerLaneParamsAugmented.leftLane.range(sampleIdx));
            %raw
            %     followerLeftLaneRaw_rotated = rotateLane(followerLeftLaneRaw,relativeHeading);
            followerLeftLaneRawIntegral = trapz(followerLeftLaneRaw.longitudinal, followerLeftLaneRaw.lateral - followerLaneParamsRaw.leftLane.distance(sampleIdx));
            followerLeftLaneRawIntegral_normalized = followerLeftLaneRawIntegral / followerLaneParamsRaw.leftLane.range(sampleIdx);
            %Follower Alone
            followerLeftLaneAlone = trapz(followerAloneLeftLane.longitudinal, followerAloneLeftLane.lateral - followerAloneLaneParams.leftLane.distance(sampleIdx));
            followerLeftLaneAloneIntegral_normalized = followerLeftLaneAlone / followerAloneLaneParams.leftLane.range(sampleIdx);
            
            %Right Lane
            %augmented
            %     followerRightLaneAugmented_rotated = rotateLane(followerRightLaneAugmented,relativeHeading);
            followerRightLaneAugmentedIntegral = trapz(followerRightLaneAugmented.longitudinal,followerRightLaneAugmented.lateral - followerLaneParamsAugmented.rightLane.distance(sampleIdx));
            followerRightLaneAugmentedIntegral_normalized = followerRightLaneAugmentedIntegral / (followerLaneParamsAugmented.rightLane.range(sampleIdx));
            %raw
            %     followerRightLaneRaw_rotated = rotateLane(followerRightLaneRaw,relativeHeading);
            followerRightLaneRawIntegral = trapz(followerRightLaneRaw.longitudinal,followerRightLaneRaw.lateral - followerLaneParamsRaw.rightLane.distance(sampleIdx));
            followerRightLaneRawIntegral_normalized = followerRightLaneRawIntegral / followerLaneParamsRaw.rightLane.range(sampleIdx);
            %Follower Alone
            followerRightLaneAlone = trapz(followerAloneRightLane.longitudinal, followerAloneRightLane.lateral - followerAloneLaneParams.rightLane.distance(sampleIdx));
            followerRightLaneAloneIntegral_normalized = followerRightLaneAlone / followerAloneLaneParams.rightLane.range(sampleIdx);
            
            
            %         LEADER
            %Right Lane
            leaderRightLaneIntegral = trapz(leaderRightLane.longitudinal, leaderRightLane.lateral - leaderLaneParams.rightLane.distance(sampleIdx));
            leaderRightLaneIntegral_normalized = leaderRightLaneIntegral / leaderLaneParams.rightLane.range(sampleIdx);
            
            %Left Lane
            leaderLeftLaneIntegral = trapz(leaderLeftLane.longitudinal,leaderLeftLane.lateral - leaderLaneParams.leftLane.distance(sampleIdx));
            leaderLeftLaneIntegral_normalized = leaderLeftLaneIntegral / leaderLaneParams.leftLane.range(sampleIdx);
            
        case 'dist'
            %         FOLLOWER
            %Left Lane
            %augmented
            %     followerLeftLaneAugmented_rotated = rotateLane(followerLeftLaneAugmented,relativeHeading);
            followerLeftLaneAugmentedIntegral = trapz(followerLeftLaneAugmented.longitudinal, followerLeftLaneAugmented.lateral);% - followerLaneParamsAugmented.leftLane.distance(sampleIdx));
            followerLeftLaneAugmentedIntegral_normalized = followerLeftLaneAugmentedIntegral / (followerLaneParamsAugmented.leftLane.range(sampleIdx));
            %raw
            %     followerLeftLaneRaw_rotated = rotateLane(followerLeftLaneRaw,relativeHeading);
            followerLeftLaneRawIntegral = trapz(followerLeftLaneRaw.longitudinal, followerLeftLaneRaw.lateral);% - followerLaneParamsRaw.leftLane.distance(sampleIdx));
            followerLeftLaneRawIntegral_normalized = followerLeftLaneRawIntegral / followerLaneParamsRaw.leftLane.range(sampleIdx);
            %Follower Alone
            followerLeftLaneAlone = trapz(followerAloneLeftLane.longitudinal, followerAloneLeftLane.lateral);% - followerAloneLaneParams.leftLane.distance(sampleIdx));
            followerLeftLaneAloneIntegral_normalized = followerLeftLaneAlone / followerAloneLaneParams.leftLane.range(sampleIdx);
            
            %Right Lane
            %augmented
            %     followerRightLaneAugmented_rotated = rotateLane(followerRightLaneAugmented,relativeHeading);
            followerRightLaneAugmentedIntegral = trapz(followerRightLaneAugmented.longitudinal,followerRightLaneAugmented.lateral);% - followerLaneParamsAugmented.rightLane.distance(sampleIdx));
            followerRightLaneAugmentedIntegral_normalized = followerRightLaneAugmentedIntegral / (followerLaneParamsAugmented.rightLane.range(sampleIdx));
            %raw
            %     followerRightLaneRaw_rotated = rotateLane(followerRightLaneRaw,relativeHeading);
            followerRightLaneRawIntegral = trapz(followerRightLaneRaw.longitudinal,followerRightLaneRaw.lateral);% - followerLaneParamsRaw.rightLane.distance(sampleIdx));
            followerRightLaneRawIntegral_normalized = followerRightLaneRawIntegral / followerLaneParamsRaw.rightLane.range(sampleIdx);
            %Follower Alone
            followerRightLaneAlone = trapz(followerAloneRightLane.longitudinal, followerAloneRightLane.lateral);% - followerAloneLaneParams.rightLane.distance(sampleIdx));
            followerRightLaneAloneIntegral_normalized = followerRightLaneAlone / followerAloneLaneParams.rightLane.range(sampleIdx);
            
            
            %         LEADER
            %Right Lane
            leaderRightLaneIntegral = trapz(leaderRightLane.longitudinal, leaderRightLane.lateral);% - leaderLaneParams.rightLane.distance(sampleIdx));
            leaderRightLaneIntegral_normalized = leaderRightLaneIntegral / leaderLaneParams.rightLane.range(sampleIdx);
            
            %Left Lane
            leaderLeftLaneIntegral = trapz(leaderLeftLane.longitudinal,leaderLeftLane.lateral);% - leaderLaneParams.leftLane.distance(sampleIdx));
            leaderLeftLaneIntegral_normalized = leaderLeftLaneIntegral / leaderLaneParams.leftLane.range(sampleIdx);
    end

    
    
    %Augmented Area - with Leader
    leftLaneAugmented_leadFollowArea(sampleIdx) = (followerLeftLaneAugmentedIntegral_normalized - leaderLeftLaneIntegral_normalized)^2;
    %     leftLaneAugmented_leadFollowArea(sampleIdx) = (followerLeftLaneAugmentedIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
%     leftLaneRaw_leadFollowArea(sampleIdx) = (leaderLeftLaneIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
%     rightLaneRaw_leadFollowArea(sampleIdx) = (leaderRightLaneIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    rightLaneAugmented_leadFollowArea(sampleIdx) = (followerRightLaneAugmentedIntegral_normalized - leaderRightLaneIntegral_normalized)^2;
    %     rightLaneAugmented_leadFollowArea(sampleIdx) = (followerRightLaneAugmentedIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    %     rightLaneAugmented_leadFollowArea(sampleIdx) = (followerRightLaneAugmentedIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    
    %Raw Area - With Leader
        leftLaneRaw_leadFollowArea(sampleIdx) = (followerLeftLaneRawIntegral_normalized - leaderLeftLaneIntegral_normalized)^2;
    %     leftLaneRaw_leadFollowArea(sampleIdx) = (followerLeftLaneRawIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
        rightLaneRaw_leadFollowArea(sampleIdx) = (followerRightLaneRawIntegral_normalized - leaderRightLaneIntegral_normalized)^2;
    %     rightLaneRaw_leadFollowArea(sampleIdx) = (followerRightLaneRawIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    %     rightLaneRaw_leadFollowArea(sampleIdx) = (leaderRightLaneIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    
    
    
    %Augmented Area - with Unocloduded Self
    leftLaneAugmented_unocludedFollowArea(sampleIdx) = (followerLeftLaneAugmentedIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
    %     leftLaneAugmented_leadFollowArea(sampleIdx) = (followerLeftLaneAugmentedIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
%     leftLaneRaw_leadFollowArea(sampleIdx) = (leaderLeftLaneIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
%     rightLaneRaw_leadFollowArea(sampleIdx) = (leaderRightLaneIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    rightLaneAugmented_unocludedFollowArea(sampleIdx) = (followerRightLaneAugmentedIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    %     rightLaneAugmented_leadFollowArea(sampleIdx) = (followerRightLaneAugmentedIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    %     rightLaneAugmented_leadFollowArea(sampleIdx) = (followerRightLaneAugmentedIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    
    %Raw Area - With Unocluded Self
        leftLaneRaw_unocludedFollowArea(sampleIdx) = (followerLeftLaneRawIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
    %     leftLaneRaw_leadFollowArea(sampleIdx) = (followerLeftLaneRawIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
        rightLaneRaw_unocludedFollowArea(sampleIdx) = (followerRightLaneRawIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    %     rightLaneRaw_leadFollowArea(sampleIdx) = (followerRightLaneRawIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    %     rightLaneRaw_leadFollowArea(sampleIdx) = (leaderRightLaneIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
    
      
    %Leader Follower Unocluded
    leaderUnocludedFollowerAreaLeftLane(sampleIdx) = (leaderLeftLaneIntegral_normalized - followerLeftLaneAloneIntegral_normalized)^2;
    leaderUnocludedFollowerAreaRightLane(sampleIdx) = (leaderRightLaneIntegral_normalized - followerRightLaneAloneIntegral_normalized)^2;
end

%%  Plot Analytics

% figure
% plot(allTime, leftLaneAugmented_leadFollowArea,'g','LineWidth',2)
% hold on
% grid on
% plot(allTime, leftLaneRaw_leadFollowArea,'r','LineWidth',2)
% legend('Augmented Area Diff', 'RawArea Diff')
% xlabel('Time (s)')
% ylabel('Normalized Area Between Approximations (m)')
% title('Normalized Area Between Lead and Follow Approximations - Left Lane')
% 
% figure
% plot(allTime, rightLaneAugmented_leadFollowArea,'g','LineWidth',2)
% hold on
% grid on
% plot(allTime, rightLaneRaw_leadFollowArea,'r','LineWidth',2)
% legend('Augmented Area Diff', 'RawArea Diff')
% xlabel('Time (s)')
% ylabel('Normalized Area Between Approximations (m)')
% title('Normalized Area Between Lead and Follow Approximations - Right Lane')

timeSteps = numel(allTime);

%Plot Analytics
figure
% plot(allTime, leftLaneAugmented_unocludedFollowArea,'m','LineWidth',2)
plot(allTime, leftLaneAugmented_unocludedFollowArea(1:timeSteps),'m','LineWidth',2)
hold on
grid on
plot(allTime, leftLaneRaw_unocludedFollowArea(1:timeSteps),'c','LineWidth',2)
% plot(allTime, leaderUnocludedFollowerAreaLeftLane,'r','LineWidth',2)
legend('Augmented Area Diff with Unocluded Follower', 'Raw Area Diff  with Unocluded Follower')
xlabel('Time (s)')
ylabel('Normalized Area Between Approximations (m)')
title('Normalized Area Between  Unocluded Follower and Ocluded Follow Approximations - Left Lane')

figure
plot(allTime, rightLaneAugmented_unocludedFollowArea(1:timeSteps),'m','LineWidth',2)
% plot(allTime, rightLaneAugmented_unocludedFollowArea,'m','LineWidth',2)
hold on
grid on
plot(allTime, rightLaneRaw_unocludedFollowArea(1:timeSteps),'c','LineWidth',2)
% plot(allTime, leaderUnocludedFollowerAreaRightLane,'g','LineWidth',2)
legend('Augmented Area Diff with Unocluded Follower', 'Raw Area Diff  with Unocluded Follower')
xlabel('Time (s)')
ylabel('Normalized Area Between Approximations (m)')
title('Normalized Area Between  Unocluded Follower and Ocluded Follow Approximations - Right Lane')

% figure
% plot(allTime, leaderUnocludedFollowerAreaLeftLane,'g','LineWidth',2)
% xlabel('Time (s)')
% ylabel('Normalized Area Between Approximations (m)')
% legend('Area Diff Between Leader and Unocluded Follower - Left Lane')
% figure
% plot(allTime, leaderUnocludedFollowerAreaRightLane,'r','LineWidth',2)
% legend('Area Diff Between Leader and Unocluded Follower - Right Lane')
% xlabel('Time (s)')
% ylabel('Normalized Area Between Approximations (m)')

%% Kalman Filter Update
function [laneHeadingAngleEst, Sigma_min]  = yawEstimate_propagate(sentHeadingAngle, Sigma_plus, relativeHeading, sigma_relativeHeading)
laneHeadingAngleEst = sentHeadingAngle + relativeHeading ;
%  laneHeadingAngleEst = atan(tan(sentHeadingAngle) - tan(relativeHeading)) ;
Sigma_min = Sigma_plus + sigma_relativeHeading^2;
end

function [distFromLaneEst, Sigma_min]  = distEstimate_propagate(laneWidth, Sigma_plus, usableDist, sigma_u)
distFromLaneEst = laneWidth - usableDist;
Sigma_min = Sigma_plus + sigma_u^2;
end

function [x_hat_plus, Sigma_plus] = KF_update(x_hat_min, Sigma_min, z, sigma_measured)
k = Sigma_min / (Sigma_min + sigma_measured^2);
x_hat_plus = x_hat_min + k*(z - x_hat_min);
Sigma_plus = (1 - k)*Sigma_min;
end


%% Rotation
function  rotatedLane = rotateLane(lane,relativeHeading)
%Rotate the generated clothoid vectors by the Heading = integrated YawRate
rotationMtrx = [cos(relativeHeading) -sin(relativeHeading) ; sin(relativeHeading) cos(relativeHeading)];
rotatedLane_temp= rotationMtrx * [lane.longitudinal; lane.lateral];
rotatedLane.lateral = rotatedLane_temp(2,:);
rotatedLane.longitudinal = rotatedLane_temp(1,:);
end

%% Headway time adjustment
function [followerHeadwayVector ,followerDistanceHeadwayVector] = leader_follower_timing(followerData,leaderData)
for followerIdx = 1:size(followerData,2)
    followerTime(followerIdx) = followerData(followerIdx).Time;
    followerStatus(followerIdx) = followerData(followerIdx).ActorPoses(1);
    followerSpeed(followerIdx) = sqrt(followerStatus(followerIdx).Velocity(1)^2  + followerStatus(followerIdx).Velocity(2)^2);
    followerRadar = followerData(followerIdx).ObjectDetections;
end
estimatedDistanceTraveled_follower = cumtrapz(followerTime,followerSpeed);
for leaderIdx = 1:size(leaderData,2)
    leaderTime(leaderIdx) = leaderData(leaderIdx).Time;
    leaderStatus(leaderIdx) = leaderData(leaderIdx).ActorPoses(1);
    leaderSpeed(leaderIdx) = sqrt(leaderStatus(leaderIdx).Velocity(1)^2  + leaderStatus(leaderIdx).Velocity(2)^2);
    leaderRadar = leaderData(leaderIdx).ObjectDetections;
end
estimatedDistanceTraveled_leader= cumtrapz(leaderTime,leaderSpeed);
followerHeadwayVector = zeros(1,size(followerTime,2)); %initialize a delay vector for the size of the time vector for the stat currently being computed

for timeIdx = 1:size(followerTime,2)
    if timeIdx > numel(leaderStatus)
        break
    end
    currFollowerTime = followerTime(timeIdx);
    %Estimate the distance to leader
    currSum = 0;
    for radIdx = 1:size(followerRadar,1)
        currMeas = followerRadar{radIdx, 1}.Measurement(1);
        currSum= currSum + currMeas;
    end
    %     currDistanceAhead = currSum / radIdx;
    leaderPose = leaderStatus(timeIdx).Position;
    %     disp(leaderPose)
    followerPose = followerStatus(timeIdx).Position;
    %     disp(followerPose)
    currDistanceAhead = sqrt((leaderPose(1) - followerPose(1))^2 + (leaderPose(2) - followerPose(2))^2);
    speed_atSample_follower  = followerSpeed(timeIdx);
    followerDistanceHeadwayVector(timeIdx) = currDistanceAhead;
    if timeIdx == 2
        %         followerHeadwayVector(1,:) = (currDistanceAhead - ((estimatedDistanceTraveled_follower(timeIdx) - estimatedDistanceTraveled_follower(timeIdx - 1)) - ...
        %             (estimatedDistanceTraveled_leader(timeIdx) - estimatedDistanceTraveled_leader(timeIdx - 1)))) / speed_atSample_follower;
        followerHeadwayVector(1,:) = currDistanceAhead / speed_atSample_follower;
    elseif timeIdx > 2
        %         followerHeadwayVector(1,timeIdx:end) = (currDistanceAhead - ((estimatedDistanceTraveled_follower(timeIdx) - estimatedDistanceTraveled_follower(timeIdx - 1)) - ...
        %             (estimatedDistanceTraveled_leader(timeIdx) - estimatedDistanceTraveled_leader(timeIdx - 1)))) / speed_atSample_follower;
        followerHeadwayVector(1,timeIdx:end) = currDistanceAhead / speed_atSample_follower;
    end
end
end


%% Collect all data into a unified structure for ease of use
function unifiedStruct = unify_signals(leader_stats,follower_stats)

unifiedStruct = struct();
%% Plotter
unifiedStruct.structure = 'unified';
currFollowerStats = follower_stats;
currLeaderStats = leader_stats;
allStatCategories_follower= fieldnames(currFollowerStats);
for categoryIdx = 2:3
    currStatCategory = allStatCategories_follower{categoryIdx};
    allFollowerStats= currFollowerStats.(currStatCategory);
    allLeaderStats = currLeaderStats.(currStatCategory);
    allStatNames = fieldnames(allLeaderStats);
    currHeadwayLeaderValue = [];
    currHeadwayFollowerValue = [];
    if strcmp(currStatCategory,'laneStats')
        allLanes = fieldnames(allLeaderStats);
        for laneIdx = 1:numel(allLanes)
            currLane = allLanes{laneIdx};
            allStats = allFollowerStats.(currLane);
            allStatNames = fieldnames(allStats);
            for statIdx = 1:numel(allStatNames)
                currStatName = allStatNames{statIdx};
                augmentIdx = 0;
                followerIdxTemp = 1;
                for timeIdx = 1:numel(leader_stats.headwayedTime)
                    if timeIdx > numel(allFollowerStats.(currLane).(currStatName))
                        break
                    end
                    currHeadwayTime = leader_stats.headwayedTime(timeIdx);
                    [~,followerIdx0] = min(abs(follower_stats.time - currHeadwayTime));
                    followerIdx_plus = followerIdx0 + 1;
                    followerIdx_minus = followerIdx0 - 1;
                    if followerIdx0 == numel(follower_stats.time) && lastVal
                        break
                    elseif followerIdx0 == numel(follower_stats.time)
                        lastVal = true;
                    end
                    if followerIdx_minus == 0
                        followerIdx_minus = followerIdx0;
                    end
                    if followerIdx_plus > numel(follower_stats.time)
                        followerIdx_plus = followerIdx_minus;
                    end
                    
                    currLeaderPose = leader_stats.globalOrientation(1,timeIdx).Position;
                    currFollowerPose_plus = follower_stats.globalOrientation(1,followerIdx_plus).Position;
                    currFollowerPose_minus=  follower_stats.globalOrientation(1,followerIdx_minus).Position;
                    
                    plusDist = sqrt((currLeaderPose(1) - currFollowerPose_plus(1))^2 + (currLeaderPose(2) - currFollowerPose_plus(2))^2);
                    minusDist = sqrt((currLeaderPose(1) - currFollowerPose_minus(1))^2 + (currLeaderPose(2) - currFollowerPose_minus(2))^2);
                    
                    if plusDist > minusDist
                        interpMode = 'minus';
                        followerIdx = followerIdx_minus;
                    else
                        interpMode = 'plus';
                        followerIdx = followerIdx_plus;
                    end
                    
                    if followerIdx0 > numel(follower_stats.time) || followerIdx > numel(follower_stats.time)
                        for i = 1:augmentIdx-1
                            currHeadwayLeaderValue(i,:) =  allLeaderStats.(currLane).(currStatName)((i));% allLeaderStats(1,i).(allStatNames{statIdx});
                        end
                        currHeadwayTimeVec = leader_stats.headwayedTime(1:augmentIdx);
                        continue
                    else
                        augmentIdx = augmentIdx + 1;
                        for i = 1:augmentIdx
                            currHeadwayLeaderValue(i,:) =  allLeaderStats.(currLane).(currStatName)((i));% allLeaderStats(1,i).(allStatNames{statIdx});
                        end
                        
                        switch interpMode
                            case 'plus'
                                currSamplePt = [follower_stats.time(followerIdx0 - 1); follower_stats.time(followerIdx0); follower_stats.time(followerIdx)];
                                currSampleVal = [allFollowerStats.(currLane).(currStatName)(followerIdx0 - 1); allFollowerStats.(currLane).(currStatName)(followerIdx0); allFollowerStats.(currLane).(currStatName)(followerIdx)];
                            case 'minus'
                                currSamplePt = [follower_stats.time(followerIdx - 1); follower_stats.time(followerIdx); follower_stats.time(followerIdx0)];
                                currSampleVal = [allFollowerStats.(currLane).(currStatName)(followerIdx - 1); allFollowerStats.(currLane).(currStatName)(followerIdx); allFollowerStats.(currLane).(currStatName)(followerIdx0)];
                        end
                        
%                         currHeadwayTimeVec = leader_stats.headwayedTime(1:augmentIdx);
%                         currSamplePt = [follower_stats.time(followerIdx); follower_stats.time(followerIdx0)];
%                         currSampleVal = [allFollowerStats.(currLane).(currStatName)(followerIdx) ; allFollowerStats.(currLane).(currStatName)(followerIdx0)];
                        queryPt = currHeadwayTime;
%                                         interpVal = interp1(currSamplePt, currSampleVal, queryPt);
                        interpVal = interp1(currSamplePt, currSampleVal, queryPt);

%                         ax = abs(currSamplePt(1) - queryPt);
%                         bx = abs(currSamplePt(2) - queryPt);
%                         cx = abs(currSamplePt(3) - queryPt);
%                         interpVal = (bx*currSampleVal(1,:) + ax*currSampleVal(2,:)) / (ax + bx);
                        
                        
                        
                        
                        
%                         currHeadwayTimeVec = leader_stats.headwayedTime(1:augmentIdx);
% %                         interpVal  = (allFollowerStats.(currLane).(currStatName)(followerIdx1) + allFollowerStats.(currLane).(currStatName)(followerIdx2)) / 2;
                        currHeadwayFollowerValue(augmentIdx,:) = interpVal;
                    end
                end
                unifiedStruct.(currStatCategory).(currLane).(currStatName).leaderValues = currHeadwayLeaderValue;
                unifiedStruct.timeVec =  leader_stats.time(1:augmentIdx);
                unifiedStruct.(currStatCategory).(currLane).(currStatName).followerValues = currHeadwayFollowerValue;
            end
        end
    else
        for statIdx = 2:numel(allStatNames)
            currStatName = allStatNames{statIdx};
            currHeadwayLeaderValue = [];
            currHeadwayFollowerValue = [];
            augmentIdx = 0;
            followerIdxTemp = 1;
            lastVal = false;
            for timeIdx = 1:numel(leader_stats.time)
                if timeIdx > numel(allFollowerStats)
                    break
                end
%                 currHeadwayTime = leader_stats.headwayedTime(timeIdx);
                
%                 followerIdx1 = find((follower_stats.time) >=currHeadwayTime,1,'first');
%                 followerIdx2 = find((follower_stats.time) <=currHeadwayTime,1,'last');

%                     [~,followerIdx0] = min(abs(follower_stats.time - currHeadwayTime));
%                     followerIdx_plus = followerIdx0 - 1 ;



                    currHeadwayTime = leader_stats.headwayedTime(timeIdx);
                    [~,followerIdx0] = min(abs(follower_stats.time - currHeadwayTime));
                    followerIdx_plus = followerIdx0 + 1;
                    followerIdx_minus = followerIdx0 - 1;
                    if followerIdx0 == numel(follower_stats.time) && lastVal
                        break
                    elseif followerIdx0 == numel(follower_stats.time)
                        lastVal = true;
                    end
                    if followerIdx_minus == 0
                        followerIdx_minus = followerIdx0;
                    end
                    if followerIdx_plus > numel(follower_stats.time)
                        followerIdx_plus = followerIdx0;
                    end
                    
                    currLeaderPose = leader_stats.globalOrientation(1,timeIdx).Position;
                    currFollowerPose_plus = follower_stats.globalOrientation(1,followerIdx_plus).Position;
                    currFollowerPose_minus=  follower_stats.globalOrientation(1,followerIdx_minus).Position;
                    
                    plusDist = sqrt((currLeaderPose(1) - currFollowerPose_plus(1))^2 + (currLeaderPose(2) - currFollowerPose_plus(2))^2);
                    minusDist = sqrt((currLeaderPose(1) - currFollowerPose_minus(1))^2 + (currLeaderPose(2) - currFollowerPose_minus(2))^2);
                    
                    if plusDist > minusDist
                        interpMode = 'minus';
                        followerIdx = followerIdx_minus;
                    else
                        interpMode = 'plus';
                        followerIdx = followerIdx_plus;
                    end









%                 
%                 if ~isempty(followerIdx1) && ~isempty(followerIdx2)
%                     if abs(follower_stats.time(followerIdx1)  - currHeadwayTime) <= abs(follower_stats.time(followerIdx2) - currHeadwayTime)
%                         followerIdx = followerIdx1;
%                     elseif abs(follower_stats.time(followerIdx1)  - currHeadwayTime) > abs(follower_stats.time(followerIdx2) - currHeadwayTime)
%                         followerIdx = followerIdx2;
%                     end
%                     augmentIdx = augmentIdx + 1;
%                 elseif ~isempty(followerIdx1) && isempty(followerIdx2)
%                     followerIdx = followerIdx1;
%                 elseif isempty(followerIdx1) && ~isempty(followerIdx2)
%                     followerIdx = followerIdx2;
%                 else
%                     continue
%                 end
                
                %                 [~,followerIdx] = min(abs(follower_stats.time - currHeadwayTime));
                %                 followerIdx = find((follower_stats.time) >=currHeadwayTime,1,'first');
                %                 if followerIdxTemp == followerIdx && currHeadwayTime < 0
                %                     continue
                %                 else
                %                     augmentIdx = augmentIdx + 1;
                %                 end
                %                 followerIdxTemp = followerIdx;
                
%                 
%                 if isempty(followerIdx)
%                     for i = 1:augmentIdx
%                         currHeadwayLeaderValue(i,:) =  allLeaderStats(1,i).(currStatName);
%                     end
%                     currHeadwayTimeVec = leader_stats.headwayedTime(1:augmentIdx);
%                     continue
%                 end
                if followerIdx0 > numel(allFollowerStats) || followerIdx_plus > numel(allFollowerStats)
                    for i = 1:augmentIdx
                        currHeadwayLeaderValue(i,:) =  allLeaderStats(1,i).(currStatName);
                    end
                    currHeadwayTimeVec = leader_stats.headwayedTime(1:augmentIdx);
                    continue
                else
                    augmentIdx = augmentIdx + 1;
                    for i = 1:augmentIdx
                        currHeadwayLeaderValue(i,:) =  allLeaderStats(1,i).(currStatName);
                    end
                    currHeadwayTimeVec = leader_stats.headwayedTime(1:augmentIdx);
                end
                
                switch interpMode
                    case 'plus'
                        currSamplePt = [follower_stats.time(followerIdx0); follower_stats.time(followerIdx)];
                        currSampleVal = [allFollowerStats(1,followerIdx0).(currStatName); allFollowerStats(1,followerIdx).(currStatName)];
                    case 'minus'
                        currSamplePt = [follower_stats.time(followerIdx); follower_stats.time(followerIdx0)];
                        currSampleVal = [allFollowerStats(1,followerIdx).(currStatName); allFollowerStats(1,followerIdx0).(currStatName)];
                end
%                         currSamplePt = [follower_stats.time(followerIdx_plus); follower_stats.time(followerIdx0)];
%                 currSamplePt = [follower_stats.time(followerIdx1); follower_stats.time(followerIdx2)];
%                 currSampleVal = [allFollowerStats(1,followerIdx1).(currStatName); allFollowerStats(1,followerIdx2).(currStatName)];
%                 currSampleVal = [allFollowerStats(1,followerIdx_plus).(currStatName); allFollowerStats(1,followerIdx0).(currStatName)];
                queryPt = currHeadwayTime;
%                 interpVal = interp1(currSamplePt, currSampleVal, queryPt);
                ax = abs(currSamplePt(1) - queryPt);
                bx = abs(currSamplePt(2) - queryPt);
                interpVal = (bx*currSampleVal(1,:) + ax*currSampleVal(2,:)) / (ax + bx);
                
                
                
                
%                 interpVal  = (allFollowerStats(1,followerIdx1).(currStatName) + allFollowerStats(1,followerIdx2).(currStatName)) / 2;
                currHeadwayFollowerValue(augmentIdx,:) = interpVal;
                
                if strcmp(currStatName, 'Position')
%                     tester = sqrt((currHeadwayFollowerValue(augmentIdx,1) - currHeadwayLeaderValue(augmentIdx,1))^2 + (currHeadwayFollowerValue(augmentIdx,2) - currHeadwayLeaderValue(augmentIdx,2))^2)
                end
            end
            unifiedStruct.(currStatCategory).(currStatName).leaderValues = currHeadwayLeaderValue;
            unifiedStruct.timeVec =  leader_stats.time(1:augmentIdx);
            unifiedStruct.(currStatCategory).(currStatName).followerValues = currHeadwayFollowerValue;
        end
    end
end
end

%% Generate Clothoid lane approximations

function lane = compute_lane(laneParameters,sampleIdx)
curr_yawToLane = laneParameters.headingAngle(sampleIdx);
curr_laneRange = laneParameters.range(sampleIdx);
curr_laneCrvtr =  laneParameters.curvature(sampleIdx);
curr_laneCrvtrChg = laneParameters.curvatureDerivative(sampleIdx);
curr_distToLane = laneParameters.distance(sampleIdx);

lane = get_clothoid_approx(curr_yawToLane,curr_laneRange, curr_laneCrvtr,curr_laneCrvtrChg,curr_distToLane);

    function [lane_approx] = get_clothoid_approx(yawToLane, laneRange, laneCrvtr, laneCrvtrChg, distToLane, varargin)
        horizonStep = 1; %step size for iterating through from the minimum range to the maximum range
        %     distanceTraveled
        
        if ~isnan(laneRange) || laneRange <= 125
            horizon = 0:horizonStep:laneRange;
            for rangeIdx = 1:size(horizon,2) %for all longitudinal horizons to be approximated
                currRange = horizon(rangeIdx);
                lane_approx.lateral(rangeIdx)= distToLane + yawToLane*currRange *(2*pi / 360) + laneCrvtr*currRange^2 *(0.5/ 1000)...
                    + laneCrvtrChg*currRange^3*(0.16667 / (1000^2));
                lane_approx.longitudinal(rangeIdx) = currRange;
            end
        else
            lane_approx = [];
        end
    end
end
%%
function plot_values(leader, unifiedStruct)
figure;
subplot(2,1,1)
hold on;
plot(leader.time, leader.laneStats.leftLane.headingAngle,'--')
plot(unifiedStruct.timeVec,unifiedStruct.laneStats.leftLane.headingAngle.leaderValues)
plot(unifiedStruct.timeVec, unifiedStruct.laneStats.leftLane.headingAngle.followerValues)
title('Heading Angle To Left Lane')
legend('Lead Vehicle', 'Follow Vehicle')

subplot(2,1,2)
hold on;
plot(leader.time,leader.laneStats.rightLane.headingAngle,'--')
plot(unifiedStruct.timeVec, unifiedStruct.laneStats.rightLane.headingAngle.leaderValues)
plot(unifiedStruct.timeVec, unifiedStruct.laneStats.rightLane.headingAngle.followerValues)
title('Heading Angle To Right Lane')

% figure;
% subplot(2,1,1)
% hold on;
% plot(leader.time,leader.curvature,'--')
% plot(leader.headwayedTime,leader.curvature)
% plot(follower.time, follower.curvature_follower)
% title('Curvature Left Lane')
% legend('Lead Vehicle', 'Lead Vehicle Headwayed', 'Follow Vehicle')
%
% subplot(2,1,2)
% hold on;
% plot(leader.time,leader.curvature,'--')
% plot(leader.headwayedTime,leader.curvature)
% plot(follower.time, follower.curvature)
% title('Curvature Right Lane')
%
%
% figure;
% subplot(2,1,1)
% hold on;
% plot(leader.time,leader.curvatureDerivative,'--')
% plot(leader.headwayedTime,leader.curvatureDerivative)
% plot(follower.time, follower.curvatureDerivative)
% title('Curvature Derivative Left Lane')
% legend('Lead Vehicle', 'Lead Vehicle Headwayed', 'Follow Vehicle')
%
% subplot(2,1,2)
% hold on;
% plot(leader.time,leader.curvatureDerivative,'--')
% plot(leader.headwayedTime,leader.curvatureDerivative)
% plot(follower.time, follower.curvatureDerivative)
% title('Curvature Derivative Right Lane')
%
% figure;
% subplot(2,1,1)
% hold on;
% plot(leader.time,leader.distance,'--')
% plot(leader.headwayedTime,leader.distance)
% plot(follower.time, follower.distance)
% title('Distance To Left Lane')
% legend('Lead Vehicle', 'Lead Vehicle Headwayed', 'Follow Vehicle')
%
% subplot(2,1,2)
% hold on;
% plot(leader.time,leader.distance,'--')
% plot(leader.headwayedTime,leader.distance)
% plot(follower.time, follower.distance)
% title('Distance To Right Lane')
end