function [x_hat_min, Sigma_min]  = KF_propagate(x_hat_plus, Sigma_plus, u, sigma_u, dt)
x_hat_min = x_hat_plus + u*dt;
Sigma_min = Sigma_plus + sigma_u^2;
% Sigma_min = (Sigma_plus^2 + sigma_u^2)^(1/2);
end