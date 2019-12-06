
theta_b = (blue(1).ActorPoses(1).Yaw);
theta_o = (orange(1).ActorPoses(2).Yaw);
delTheta = theta_b - theta_o;
y_b_right = (blue(1).LaneDetections.LaneBoundaries(1,2).LateralOffset);
y_o_right = (orange(1).LaneDetections.LaneBoundaries(1,2).LateralOffset);

phi_b_right = (blue(1).LaneDetections.LaneBoundaries(1,2).HeadingAngle);
phi_o_right = (orange(1).LaneDetections.LaneBoundaries(1,2).HeadingAngle);

rho_b_right = (blue(1).LaneDetections.LaneBoundaries(1,2).Curvature);
rho_o_right = (orange(1).LaneDetections.LaneBoundaries(1,2).Curvature);

rhoDot_b_right = (blue(1).LaneDetections.LaneBoundaries(1,2).CurvatureDerivative);
rhoDot_o_right = (orange(1).LaneDetections.LaneBoundaries(1,2).CurvatureDerivative);

y_b_left = (blue(1).LaneDetections.LaneBoundaries(1,1).LateralOffset);
y_o_left = (orange(1).LaneDetections.LaneBoundaries(1,1).LateralOffset);

phi_b_left = (blue(1).LaneDetections.LaneBoundaries(1,1).HeadingAngle);
phi_o_left = (orange(1).LaneDetections.LaneBoundaries(1,1).HeadingAngle);

rho_b_left= (blue(1).LaneDetections.LaneBoundaries(1,1).Curvature);
rho_o_left = (orange(1).LaneDetections.LaneBoundaries(1,1).Curvature);

rhoDot_b_left = (blue(1).LaneDetections.LaneBoundaries(1,1).CurvatureDerivative);
rhoDot_o_left = (orange(1).LaneDetections.LaneBoundaries(1,1).CurvatureDerivative);
x = 0;

for i = 1:33
    c(i) = y_o_left + phi_o_left*x*(pi /180) + rho_o_left*x^2*(0.5)*(pi/180) + rhoDot_o_left*x^3 *(1/6)*(pi / 180);

    cR(i) = y_o_right + phi_o_right*x*(2*pi / 360) + rho_o_right*x^2*(0.5/ 1)*(2*pi / 360) + rhoDot_o_right*x^3 *(0.16667 / (1^2))*(2*pi / 360);
    x = x + 0.9768;
    xp(i) = x;
%     distToLane + yawToLane*currRange *(2*pi / 360) + laneCrvtr*currRange^2 *(0.5/ 1000)...
%                     + laneCrvtrChg*currRange^3*(0.16667 / (1000^2));
end
% figure
plot(c, xp)
a = gca;
a.XDir = 'reverse';
hold on
plot(cR, xp)
a = gca;
a.XDir = 'reverse';

%%
delThetaRads = deg2rad(delTheta);
means = (y_o_left + y_b_left) / 2;
theta_bRads = deg2rad(theta_b);
theta_oRads = deg2rad(theta_o);

if theta_o <= theta_b
    sLeft_o = 1;
    sLeft_b = sqrt(y_b_left^2 + y_o_left^2 - 2*y_o_left*y_b_left*cos(delThetaRads)) + sLeft_o;
else
    sLeft_b = 0;
    sLeft_o = sqrt(y_b_left^2 + y_o_left^2 - 2*y_o_left*y_b_left*cos(delThetaRads)) + sLeft_b;
end
% sLeft_o = 0;
if theta_o <= theta_b
    sRight_o = 0;
    sRight_b = sqrt(y_b_right^2 + y_o_right^2 - 2*y_o_right*y_b_right*cos(delThetaRads)) + sRight_o;
else
    sRight_b = 0;
    sRight_o = sqrt(y_b_right^2 + y_o_right^2 - 2*y_o_right*y_b_right*cos(delThetaRads)) + sRight_b;
end


% s_o = 0;
phi_o_left_est = delThetaRads;
phi_o_right_est = delThetaRads;
temp1 = 0;
check1 = 1;
temp2 = 0;
check2 = 1;
iter = 0;
rhoMean  = (rho_o_left + rho_b_left) / 2;
rhoDotMean =  (rhoDot_o_left + rhoDot_b_left) / 2;

while abs(check1) > 0.001 && abs(check2) > 0.001
    if abs(check1) > 1 || abs(check2) > 1
        break
    end
    iter = iter + 1;
%     phi_o_left_est = (theta_oRads - phi_o_left_est) - (phi_o_left_est - tan(theta_oRads - phi_o_left_est) / (2*cos(theta_oRads + phi_o_left_est)^2 + 2));
    phi_o_left_est = tan(theta_oRads + phi_o_left_est) - (rho_o_left)*sLeft_o - (rhoDot_o_left)*(sLeft_o^2)*(1/2);
    phi_o_right_est = tan(theta_oRads - phi_o_right_est) - deg2rad(rho_o_right)*sRight_o - deg2rad(rhoDot_o_right)*sRight_o^2/2;
%     phi_o_left_est =  atan(phi_o_left_est + deg2rad(rhoMean)*s_o + deg2rad(rhoDotMean)*s_o^2*(1/2)) - ...
%             atan(deg2rad(phi_b_left) + deg2rad(rhoMean)*s_b + deg2rad(rhoDotMean)*s_b^2*(1/2)) + deg2rad(phi_b_left) - delThetaRads;
    check1 = abs(temp1) -abs(phi_o_left_est);
    check2 = abs(temp2) - abs(phi_o_right_est);
    temp1 = phi_o_left_est;
    temp2 = phi_o_right_est;
end
phi_o_leftRads = deg2rad(phi_o_left);
phi_o_rightRads = deg2rad(phi_o_right);
disp(phi_o_left_est - phi_o_leftRads)
disp(phi_o_right_est - phi_o_rightRads)
iter
% function F = findA(delTheta, phiLead, phiFollow)
% F = delTheta + atan(phiLead) - phiLead + phiFollow - atan(phiFollow);
% end
% 
% end
% init_b = theta_bMo;
% estimate_b = fsolve(@(phib)atan(phib) - theta_b, init_b)
