figure
subplot(2,1,1)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.leftLane.curvature)
plot(allTime, followerAloneLaneParams.leftLane.curvature(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Left Lane Curvature')
ylabel('Curvature (deg/m)')

%%
followerCurvature_left = followerLaneParamsRaw.leftLane.curvature;
unoccludedCurvature_left= followerAloneLaneParams.leftLane.curvature(1:706);
curvatureDiff_left = abs(followerCurvature_left - unoccludedCurvature_left);
% headingAreaDiff_right = abs(followerHeadingArea_right - unoccludedHeadingArea) * 0.1;
% figure
% plot(headingAreaDiff_right)
a = mean(curvatureDiff_left,'omitnan')
b = mean(abs(followerCurvature_left),'omitnan')
a/b * 100

%%

subplot(2,1,2)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.rightLane.curvature)
plot(allTime, followerAloneLaneParams.rightLane.curvature(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Right Lane Curvature')
ylabel('Curvature (deg/m)')

%%
followerCurvature_right = followerLaneParamsRaw.rightLane.curvature;
unoccludedCurvature_right = followerAloneLaneParams.rightLane.curvature(1:706);
curvatureDiff_right= abs(followerCurvature_right - unoccludedCurvature_right);
% headingAreaDiff_right = abs(followerHeadingArea_right - unoccludedHeadingArea) * 0.1;
% figure
% plot(headingAreaDiff_right)
curDiffInt_right = trapz(allTime, abs(curvatureDiff_right));
a = mean(curvatureDiff_right,'omitnan')
b = mean(abs(followerCurvature_right),'omitnan')
a/b * 100

%%

%%
figure
subplot(2,1,1)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.leftLane.curvatureDerivative)
plot(allTime, followerAloneLaneParams.leftLane.curvatureDerivative(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Left Lane Curvature Rate of Change')
ylabel('Curvature Rate of Change (deg/m^2)')

%%
followerCurvatureDer_right = followerLaneParamsRaw.leftLane.curvatureDerivative;
unoccludedCurvatureDer_right = followerAloneLaneParams.leftLane.curvatureDerivative(1:706);
curvatureDerDiff_right= followerCurvatureDer_right - unoccludedCurvatureDer_right;
unoccludedCurvatureDerInt_right = trapz(allTime, unoccludedCurvatureDer_right)
curvatureDerDiffInt_right = trapz(allTime, curvatureDerDiff_right)

% headingAreaDiff_right = abs(followerHeadingArea_right - unoccludedHeadingArea) * 0.1;
% figure
% plot(headingAreaDiff_right)
% a = mean(abs(curvatureDerDiff_right),'omitnan')
% b = mean(abs(followerCurvatureDer_right),'omitnan')
% a/b * 100


%%
followerCurvature_right = followerLaneParamsRaw.rightLane.curvature;
unoccludedCurvature_right= followerAloneLaneParams.rightLane.curvature(1:706);
curvatureDiff_right = followerCurvature_right - unoccludedCurvature_right;
curvatureDiffInt_right = trapz(allTime, abs(curvatureDiff_right));
% figure
% plot(curvatureAreaDiff_right)
% mean(curvatureAreaDiff_right)
% max(curvatureAreaDiff_right)

%%

subplot(2,1,2)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.rightLane.curvatureDerivative)
plot(allTime, followerAloneLaneParams.rightLane.curvatureDerivative(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Right Lane Curvature Rate of Change')
ylabel('Curvature Rate of Change(deg/m^2)')

%%
figure
subplot(2,1,1)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.leftLane.headingAngle)
plot(allTime, followerAloneLaneParams.leftLane.headingAngle(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Vehicle Angle to Left Lane')
ylabel('Vehicle Angle to the Lane (deg)')

%%
followerHeading_left = followerLaneParamsRaw.leftLane.headingAngle;
unoccludedHeading_left = followerAloneLaneParams.leftLane.headingAngle(1:706);
headingDiff_left = followerHeading_left - unoccludedHeading_left;
headingAreaDiff_left = trapz(allTime, abs(headingDiff_left));
% figure
% plot(allTime, headingAreaDiff)
% headingAngleDiffRight = trapz(allTime, abs(headingAreaDiff_left))
% mean(headingAreaDiff_left)
% max(headingAreaDiff_left)
%%

subplot(2,1,2)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.rightLane.headingAngle)
plot(allTime, followerAloneLaneParams.rightLane.headingAngle(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Vehicle Angle to Right Lane')
ylabel('Vehicle Angle to the Lane (deg)')

%%
followerHeading_right = followerLaneParamsRaw.rightLane.headingAngle;
unoccludedHeading_right= followerAloneLaneParams.rightLane.headingAngle(1:706);
headingDiff_right = abs(followerHeading_right - unoccludedHeading_right);
headingDiffInt_right = trapz((headingDiff_right));
% headingAreaDiff_right = abs(followerHeadingArea_right - unoccludedHeadingArea) * 0.1;
% figure
% plot(headingAreaDiff_right)
% a = mean(abs(headingDiff_right),'omitnan')
% b = mean(abs(followerHeading_right),'omitnan')
% a/b
% max(headingDiff_right)
% max(followerHeading_right)


%%
figure
subplot(2,1,1)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.leftLane.distance)
plot(allTime, followerAloneLaneParams.leftLane.distance(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Distance to Left Lane')
ylabel('Distance to Lane (m)')

%%
followerDistance_left = followerLaneParamsRaw.leftLane.distance;
unoccludedDistance_left= followerAloneLaneParams.leftLane.distance(1:706);
distanceDiff_left = followerDistance_left - unoccludedDistance_left;
distanceDiffInt_left = trapz(allTime, abs(distanceDiff_left))

% figure
% plot(headingAreaDiff_right)
% a = mean(distanceDiff_left,'omitnan')
% b = mean(abs(followerDistance_left),'omitnan')
% a/b * 100
% max(distanceDiff_right)
% max(followerDistance_right)


%%

subplot(2,1,2)
hold on; grid on
a = gca;
a.FontSize = 15;
plot(allTime, followerLaneParamsRaw.rightLane.distance)
plot(allTime, followerAloneLaneParams.rightLane.distance(1:706))
legend('Raw Follower Values', 'Unoccluded Follower Values')
xlabel('Time (s)')
title('Distance to Right Lane')
ylabel('Distance to Lane (m)')

%%
followerDistance_right = followerLaneParamsRaw.rightLane.distance;
unoccludedDistance_right= followerAloneLaneParams.rightLane.distance(1:706);
distanceDiff_right = abs(followerDistance_right - unoccludedDistance_right);
distanceDiffInt_right = trapz(allTime, abs(distanceDiff_right))
unoccludedDistanceInt_right = trapz(allTime, unoccludedDistance_right)

figure
subplot(2,1,1)
plot(allTime, distanceDiff_right,'r', 'LineWidth',3)
grid on
xlabel('Time (s)')
ylabel('Distance To Lane Difference (m)')
subplot(2,1,2)
plot(allTime, distanceDiff_right,'r', 'LineWidth',3)
grid on

% headingAreaDiff_right = abs(followerHeadingArea_right - unoccludedHeadingArea) * 0.1;
% figure
% plot(headingAreaDiff_right)
% mean(distanceDiff_right,'omitnan')
% mean(abs(followerDistance_right),'omitnan')




