load('boundaries.mat')
y = lfts(:,2);
x = lfts(:,1);
dx  = gradient(x);
ddx = gradient(dx);
dy  = gradient(y);
ddy = gradient(dy);
num   = dx .* ddy - ddx .* dy;
denom = dx .* dx + dy .* dy;    
denom = sqrt(denom);
% denom = denom *10;
curvatur = num*10 ./ denom;
curvature(denom < 0) = NaN;
figure
plot(y, curvatur,'--')
a = gca;
a.XDir = 'reverse'  