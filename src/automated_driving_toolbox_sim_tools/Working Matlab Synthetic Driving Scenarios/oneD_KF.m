% ECE 6504 Advanced Topics in Robotics
% HW4: Problem 2
% 1-D KF Localization with GPS updates

clear all;
close all;
clc;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Configuration settings

N = 200;    % number of timesteps
dt = 1;     % sampling time

% Noise
sigma_u = 0.2;  % control noise std (i.e., process noise)
sigma_g = 0.2;  % GPS noise std (i.e., measurement noise)

% Initial conditions
x_true_1 = 0;   % initial starting point
x_hat_1 = 0;    % initial estimate
Sigma_1 = 0;    % initial covariance

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Real World Simulation
% provides x_true, u, z_g for all timesteps
% this function generates a random trajectory for the robot
% the true positions of the robot for all time are stored in x_true
% x_true must be used only in computing the error (and not in your KF)
%
% the control values are given by u
% use u(1,k) for the k'th propogate step
% the noisy measurements are given by z
% use z_g(1,k) for the k'th update step

% for generating the above values, we need to know the robot's trajectory
% we will generate a random trajectory
u_true = 0.2 + 0.01*rand(1,N);
u_true(1,1) = 0; % make first control zero so that the robot starts at rest

[x_true, u, z_g] = rws(N, dt, x_true_1, u_true, sigma_u, sigma_g);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Bookkeeping

% pre-allocate space for certain values we want to keep track of
x_hat_min = zeros(1,N); % state estimate after Propagation
x_hat_plus = zeros(1,N); % state estimate after update
x_hat_odo = zeros(1,N); % state estimate without updates (dead reckoning)
Sigma_odo = zeros(1,N); % covariance of dead reckoning only
Sigma_min = zeros(1,N); % covariance after Propagation
Sigma_plus = zeros(1,N); % covariance after update

% initialize those with the right values where appropriate
x_hat_min(1,1) = x_hat_1;
x_hat_plus(1,1) = x_hat_1;
x_hat_odo(1,1) = x_hat_1;
Sigma_plus(1,1) = Sigma_1;
Sigma_odo(1,1) = Sigma_1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Kalman Filter

% notice that we let the filter start with a propagation step. The first
% GPS measurement at timestep i=1 is discarded (one could implement it
% differently)
for i = 2:N
    
   % Propagation
   [x_hat_min(1,i), Sigma_min(1,i)] = KF_propagate(x_hat_plus(1,i-1), Sigma_plus(1,i-1), u(1,i), sigma_u, dt);
   
   % Calculate the dead-reckoning estimate (trajectory based purely on
   % odometry, only propagation and no updates
   [x_hat_odo(1,i), Sigma_odo(1,i)] = KF_propagate(x_hat_odo(1,i-1), Sigma_odo(1,i-1), u(1,i), sigma_u, dt);
   
   % Update
   [x_hat_plus(1,i), Sigma_plus(1,i)] = GPS_update(x_hat_min(1,i), Sigma_min(1,i), z_g(1,i), sigma_g);
   
end



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Visualization

% generate time 
t = 0:dt:(N-1)*dt;

% True state vs. posterior est
figure('Name','Trajectory'); hold on
plot(t, x_true, 'b'); 
plot(t, x_hat_plus, 'r');
plot(t, x_hat_odo, 'g');
xlabel('time (s)')
ylabel('Position (m)')
legend('True State','Posterior Estimate','Dead Reckoning')
grid on

% Error
figure('Name','Dead Reckoning Error'); hold on
plot(t, x_true - x_hat_odo);
plot(t, 3*sqrt(Sigma_odo),'r')
plot(t,-3*sqrt(Sigma_odo),'r')
xlabel('time (s)')
ylabel('x-x_{hat} (m)')
legend('Dead Reckoning Position Error','3\sigma - bound')
grid on

% Error
figure('Name','Position Error'); hold on
plot(t, x_true-x_hat_plus) 
plot(t, 3*sqrt(Sigma_plus),'r')
plot(t,-3*sqrt(Sigma_plus),'r')
legend('KF Position Estimate Error','3\sigma - bound')
xlabel('time (s)')
ylabel('Error (m)')
grid on

