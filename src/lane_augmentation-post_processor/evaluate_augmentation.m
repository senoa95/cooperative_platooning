%%
clear 'augAreaDelta'
laneRange = 10; %assuming a constant range in meters - this is tunable
augAreaDelta = zeros(size(follow_lane_struct.augLane));
for i = 1:size(follow_lane_struct.augLane,2)
    rawLane = compute_lane(follow_lane_struct.lane,laneRange,i);
    augLane = compute_lane(follow_lane_struct.augLane,laneRange,i);
    rawLaneIntegral = trapz(rawLane.longitudinal,rawLane.lateral);
    augLaneIntegral = trapz(augLane.longitudinal,augLane.lateral);
    rawLaneIntegral_normalized = rawLaneIntegral / 1;
    augLaneIntegral_normalized = augLaneIntegral / 1;
    augAreaDelta(1,i) = (augLaneIntegral_normalized - rawLaneIntegral_normalized)^2;
end
figure
plot(time,augAreaDelta)
ylim([0,0.4])

function lane = compute_lane(laneParameters,currentRange, sampleIdx)
curr_yawToLane = laneParameters(sampleIdx).Phi;
curr_laneCrvtr =  laneParameters(sampleIdx).Rho;
curr_laneCrvtrChg = laneParameters(sampleIdx).RhoDot;
curr_distToLane = laneParameters(sampleIdx).Y;

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