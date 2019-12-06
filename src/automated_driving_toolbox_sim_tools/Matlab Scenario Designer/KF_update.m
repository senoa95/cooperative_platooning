function [x_hat_plus, Sigma_plus] = KF_update(x_hat_min, Sigma_min, z, sigma_measured)
k = Sigma_min / (Sigma_min + sigma_measured^2);
x_hat_plus = x_hat_min + k*(z - x_hat_min);
% Sigma_plus = ((1 - k)*Sigma_min^2)^(1/2);
Sigma_plus = (1 - k)*Sigma_min;
end