%% Rotation
function  rotatedLane = rotateLane(LeadLane,relativeHeading)
rotationMtrx = [cos(relativeHeading) -sin(relativeHeading) ; sin(relativeHeading) cos(relativeHeading)];
rotatedLane_temp= rotationMtrx * [LeadLane.longitudinal; LeadLane.lateral];
rotatedLane.lateral = rotatedLane_temp(2,:);
rotatedLane.longitudinal = rotatedLane_temp(1,:);
end