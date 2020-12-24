function lane = compute_lane(laneParameters,currentRange, sampleIdx)
curr_yawToLane = laneParameters.headingAngle(sampleIdx);
curr_laneCrvtr =  laneParameters.curvature(sampleIdx);
curr_laneCrvtrChg = laneParameters.curvatureDerivative(sampleIdx);
curr_distToLane = laneParameters.distance(sampleIdx);

lane = get_clothoid_approx(curr_yawToLane,currentRange, curr_laneCrvtr,curr_laneCrvtrChg,curr_distToLane);

    function [lane_approx] = get_clothoid_approx(yawToLane, laneRange, laneCrvtr, laneCrvtrChg, distToLane, varargin)
        horizonStep = 0.5; %step size for iterating through from the minimum range to the maximum range
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