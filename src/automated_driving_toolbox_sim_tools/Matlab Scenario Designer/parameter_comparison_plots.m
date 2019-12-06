
timeSteps = numel(allTime);
%%
figure;
subplot(2,1,1)
hold on
plot(allTime, followerAloneLaneParams.rightLane.curvature(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.rightLane.curvature,'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.rightLane.curvature,'LineWidth',1.5 )
title('Right Lane Curvature')
grid on
subplot(2,1,2)
hold on
plot(allTime, followerAloneLaneParams.leftLane.headingAngle(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.leftLane.headingAngle(1:timeSteps),'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.leftLane.headingAngle(1:timeSteps),'LineWidth',1.5)
title('Left Lane Curvature')
% plot(allTime, followerLaneParamsAugmented.rightLane.headingAngle)
% plot(allTime, leaderLaneParams.rightLane.headingAngle)
% plot(allTime, followerAloneLaneParams.rightLane.curvatureDerivative(1:timeSteps))
legend('Follower Alone Right', 'Follower Augmented Right', 'Follower Raw Right')
legend('Follower Alone Left','Follower Augmented Left',  'Follower Raw Left')
% title('Heading Angle')
grid on
%%
figure;
subplot(2,1,1)
hold on
plot(allTime, followerAloneLaneParams.rightLane.curvatureDerivative(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.rightLane.curvatureDerivative(1:timeSteps),'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.rightLane.curvatureDerivative(1:timeSteps),'LineWidth',1.5 )
title('Right Lane Curvature Rate of Change')
grid on
subplot(2,1,2)
hold on
plot(allTime, followerAloneLaneParams.leftLane.curvatureDerivative(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.leftLane.curvatureDerivative(1:timeSteps),'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.leftLane.curvatureDerivative(1:timeSteps),'LineWidth',1.5)
title('Left Lane Curvature Rate of Change')
% plot(allTime, followerLaneParamsAugmented.rightLane.headingAngle)
% plot(allTime, leaderLaneParams.rightLane.headingAngle)
% plot(allTime, followerAloneLaneParams.rightLane.curvatureDerivative(1:timeSteps))
legend('Follower Alone Right', 'Follower Augmented Right', 'Follower Raw Right')
legend('Follower Alone Left','Follower Augmented Left',  'Follower Raw Left')
% title('Heading Angle')
grid on
%%
figure;
subplot(2,1,1)
hold on
plot(allTime, followerAloneLaneParams.rightLane.headingAngle(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.rightLane.headingAngle(1:timeSteps),'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.rightLane.headingAngle(1:timeSteps),'LineWidth',1.5 )
title('Right Lane Angle To EGO')
grid on
subplot(2,1,2)
hold on
plot(allTime, followerAloneLaneParams.leftLane.headingAngle(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.leftLane.headingAngle(1:timeSteps),'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.leftLane.headingAngle(1:timeSteps),'LineWidth',1.5)
title('Left Lane Angle To EGO')
% plot(allTime, followerLaneParamsAugmented.rightLane.headingAngle)
% plot(allTime, leaderLaneParams.rightLane.headingAngle)
% plot(allTime, followerAloneLaneParams.rightLane.curvatureDerivative(1:timeSteps))
legend('Follower Alone Right', 'Follower Augmented Right', 'Follower Raw Right')
legend('Follower Alone Left','Follower Augmented Left',  'Follower Raw Left')
% title('Heading Angle')
grid on
%%
figure;
subplot(2,1,1)
hold on
plot(allTime, followerAloneLaneParams.rightLane.distance(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.rightLane.distance(1:timeSteps),'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.rightLane.distance(1:timeSteps),'LineWidth',1.5 )
title('Right Lane Distance')
grid on
subplot(2,1,2)
hold on
plot(allTime, followerAloneLaneParams.leftLane.distance(1:timeSteps),'LineWidth',3)
plot(allTime, followerLaneParamsAugmented.leftLane.distance(1:timeSteps),'--','LineWidth',3)
plot(allTime, followerLaneParamsRaw.leftLane.distance(1:timeSteps),'LineWidth',1.5)
title('Left Lane Distance')
legend('Follower Alone Right', 'Follower Augmented Right', 'Follower Raw Right')
legend('Follower Alone Left','Follower Augmented Left',  'Follower Raw Left')
% title('Heading Angle')
grid on
%%
figure;hold on
plot(allTime, unifiedStruct.globalOrientation.Yaw.leaderValues(1:timeSteps))
plot(allTime, unifiedStruct.globalOrientation.Yaw.followerValues(1:timeSteps))
% plot(allTime, followerLaneParamsAugmented.leftLane.distance)
% plot(allTime, leaderLaneParams.leftLane.distance)
legend('Follower Alone','Follower Raw')
title('Distance From Lane')

%%
figure;hold on
plot(allTime, followerAloneLaneParams.rightLane.distance(1:timeSteps))
plot(allTime, followerLaneParamsRaw.rightLane.distance)
% plot(allTime, followerLaneParamsAugmented.rightLane.distance)
% plot(allTime, leaderLaneParams.rightLane.distance)
legend('Follower Alone','Follower Raw')
title('Distance From Lane')