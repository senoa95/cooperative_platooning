function [x_true, u, z_g] = rws(N, dt, x_true_1, u_true, sigma_u, sigma_g)

% state dimension
n = length(x_true_1);

% preallocate
x_true = zeros(n,N);

% for each timestep
%   apply u_true to determine x_true
x_true(:,1) = x_true_1;
for i = 2 : N
    
    % x_k = x_k-1 + uk*dt
    x_true(:,i) = x_true(:,i-1) + u_true(:,i)*dt;
    
end

% Generate noisy u by sampling from Gaussian(mean u_true, std sigma_u)
% assume first u is always zero so that the robot starts at rest
u = u_true + sigma_u .* randn(n,N);
u(:,1) = 0;

% Generate noisy z_g by sampling from Gaussian(mean x_true, std sigma_g)
z_g = x_true + sigma_g * eye(n) .* randn(n,N);

end