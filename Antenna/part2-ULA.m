clear all;
clc;
lamda=1;
BETA=2*pi/lamda;
phi=linspace(0,2*pi,1000);
theta=linspace(0,2*pi,1000);


%get distance
d=input("enter the spacing w.r.t lamda d= ");
%get number of elements
N=input("enter number of elements N= ");
%get phase shift
alpha=input("The prograssive phase shift alpha= ");

%FOR Uniform linear antenna array(ULA)
gama=linspace(0,2*pi,1000);
epsi=alpha+BETA*d*cos(gama);
AF=sin(N*epsi/2)./(N*sin(epsi/2));
AF=abs(AF);

%(1)plot relation array factor VS ePsi
figure();
plot(epsi,AF,'LineWidth',2);
xlabel('{\Psi}','fontweight','bold','fontsize',16);
ylabel('Array factor','fontweight','bold','fontsize',14);
title('array factor VS {\Psi}','fontweight','bold','fontsize',12);

%(2)polarplot Visible region pattern from (alpha-Beta*d) to (alpha+Beta*d).
figure();
ax = polaraxes;
polarplot(ax,gama,AF,'LineWidth',2);
ax.ThetaZeroLocation = 'bottom';
title("2D pattern of (ULA)");

%(3)3D Pattern for dipole antenna .
figure
[theta ,phi]=meshgrid(theta,phi);
x=AF.*sin(theta).*cos(phi);
y=AF.*sin(theta).*sin(phi);
z=AF.*cos(theta);
surf(x,y,z);
title('3D radiation pattern of (ULA)');
shading flat;



