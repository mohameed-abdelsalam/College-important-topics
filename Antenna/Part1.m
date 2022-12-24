clc;
clear;

Beta = 2*pi;
phi=linspace(0,2*pi,1000);
theta=linspace(0,2*pi,1000);

%x=L/lamda
L=input("enter length of dipole relative to lamda L= ");
if L<=0.1
    E_theta=sin(theta);
    EN=abs(E_theta);
  else 
    E_theta=abs((cos(pi*L*cos((pi/2)-theta))-cos(pi*L))./sin((pi/2)-theta));
    EN=abs((cos(Beta*L*cos(theta)/2)-cos(Beta*L/2))./sin(theta));
end


%(1)2D Pattern for dipole antenna
figure;
ax = polaraxes;
polarplot(ax,theta,EN,'LineWidth',2);
ax.ThetaZeroLocation = 'bottom';
grid on;
title(['2D pattern of L = ' num2str(L) ' Lambda'])

%(2)3D Pattern for dipole antenna

% expanding theta to span entire space
E_theta(1,1)=0;
for n=1:length(phi)
    theta(n,:)=theta(1,:);
end

% expanding phi to span entire space
phi=phi';
for m=1:length(phi)
    phi(:,m)=phi(:,1);
end

% expanding E to span entire space
for k=1:length(E_theta)
    E_theta(k,:)=E_theta(1,:);
end
 
% converting to spherical coordinates 
[x,y,z]=sph2cart(phi,theta,E_theta);
figure;
surf(x,y,z);
shading flat;
title('3D radiation pattern of diople');

