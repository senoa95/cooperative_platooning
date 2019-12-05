function isGood = validateBoundaryFcn(params)

if ~isempty(params)
    a = params(1);
    
    % Reject any curve with a small 'a' coefficient, which makes it highly
    % curved.
    isGood = abs(a) < 0.003; % a from ax^2+bx+c
else
    isGood = false;
end
end