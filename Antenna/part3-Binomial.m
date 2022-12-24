clear all;
clc;
lamda=1;
BETA=2*pi/lamda;
phi=linspace(0,2*pi,1000);
theta=linspace(0,2*pi,1000);

%get distance
distance = "enter the spacing w.r.t lamda d= ";
d=input(distance);
%get number of elements
Number = "enter number of elements N= ";
N=input(Number);
%get phase shift
shift= "The prograssive phase shift alpha= ";
alpha=input(shift);

%FOR  Nonuniformly Binomia linear antenna array
gama=linspace(0,2*pi,1000);
epsi=alpha+BETA*d*cos(gama);
u=epsi/2;
AFN=(cos(u).^(N-1));
AF=(2^(N-2)).*(cos(u).^(N-1));


%(1)plot relation array factor VS ePsi
figure();
plot(u,AFN,'LineWidth',1.5);
xlabel('{u}','fontweight','bold','fontsize',16);
ylim([0,1]);
ylabel('Array factor','fontweight','bold','fontsize',14);
title('array factor VS u','fontweight','bold','fontsize',12);

%(2)polarplot Visible region pattern from (alpha-Beta*d) to (alpha+Beta*d).
figure();
ax = polaraxes;
polarplot(ax,gama,AFN,'LineWidth',2);
ax.ThetaZeroLocation = 'bottom';
title("2D pattern of Binomial array");


%(3)3D Pattern for dipole antenna .
figure
[theta ,phi]=meshgrid(theta,phi); 
%construct cartisain coordinates from polar
x=AFN.*sin(theta).*cos(phi);
y=AFN.*sin(theta).*sin(phi);
z=AFN.*cos(theta);
surf(x,y,z);
title("3D pattern of Binomial array");
shading flat;




