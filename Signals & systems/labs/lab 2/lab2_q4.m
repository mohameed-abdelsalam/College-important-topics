%qusetion 4 :
n=linspace(-20,20,41);
t=linspace(-40,40,80*.5);

xDiscrete=cos(2*n/3);
yDiscrete=cos(8*pi*n/38);

xContinous=cos(2*t/3);
yContinous=cos(8*pi*t/38);

figure;
subplot(2,2,1);
stem(n,xDiscrete);
title('X[n]');

subplot(2,2,2);
plot(t,xContinous);
title('X[nt]');

subplot(2,2,3);
stem(n,yDiscrete);
title('Y[n]');

subplot(2,2,4);
plot(t,yContinous);
title('Y[nt]');

% NO: it's non periodic because range is [-20:20] not for all time 

