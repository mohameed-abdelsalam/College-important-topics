%To plot radiation pattern of Dolph-Chebyshev array
clc;
close all; 
lamda=1;
BETA=2*pi/lamda;
theta=linspace(0,2*pi,1000);
phi=linspace(0,2*pi,1000);


%========================get requirments from user==================
%get distance
d=input("enter the spacing w.r.t lamda d= ");
%get number of elements
N=input("enter number of elements N= ");
%get phase shift
alpha=input("The prograssive phase shift alpha= ");
%side lobe level
R0=input('Enter the side lobe level in dB = ');
Z0=cosh((1/(N-1))*acosh(R0));

%========chech if even or odd & calculate Coffecients a1&a2..... =========

% check if N even or odd, if N is even then polarity=0 else polarity=1
polarity=mod(N,2); 

if polarity==0 
     M=N/2;% when N is even equation for amp coeff
     for n=1:M
         amp=0;
         for q=n:M
             a1=((-1)^(M-q))*((Z0)^((2*q)-1));
             a2=factorial(q+M-2)*((2*M)-1);
             a3=factorial(q-n)*factorial(q+n-1)*factorial(M-q);
             amp=amp+a1*a2/a3;
         end
         amp1(n)=amp;
    end
else
    
    
 M=(N-1)/2 % when N is odd the equation for amp coeff is different
   for n=1:M+1
      for q=n:M+1
           a1=((-1)^(M-q+1))*((Z0)^(2*(q-1)));
           a2=factorial(q+M-2)*(2*M);
           
           if n==1
               epsilon=2;
             else
                epsilon=1;
           end
           a3=epsilon*factorial(q-n)*factorial(q+n-2)*factorial(M-q+1);
           amp=a1*a2/a3;
      end
           amp1(n)=amp;
   end
end

amp2=amp1 ; %Normalised amplitude
 
 
%==========================================================================
%========================to find the array factor==========================
AF=0;
gama=linspace(0,2*pi,1000);
epsi=alpha+BETA*d*cos(gama);
u=epsi/2;

if polarity==0 % if N is even
 M=N/2;
     for n=1:M
        AF=AF+(amp2(n)*cos((2*n-1).*u));
     end
else % if N is odd
     M=(N-1)/2; 
     for n=1:M
        AF=AF+(amp2(n)*cos(2*(n-1).*u)); 
     end
end
%========================(1)2D PATTERWN====================
ax = polaraxes;
polarplot(ax,theta,abs(AF),'LineWidth',1.5);
s1=title('RADIATION PATTERN OF DOLPH CHEBESHEV ARRAY');
ax.ThetaZeroLocation = 'bottom';
grid on;

%========================(2)array factor VS Z===================
%(1)plot relation between array factor VS ePsi
Z0=cosh((1/(N-1))*acosh(R0))
Z_limits = linspace(-Z0,Z0,500);
AF_Z = cosh((N-1).*acosh(Z_limits));

figure();
plot(Z_limits,double(abs(AF_Z)),'LineWidth',1.5);
xlabel('Z','fontweight','bold','fontsize',12);
ylabel('Array factor','fontweight','bold','fontsize',14);
title('array factor VS Z','fontweight','bold','fontsize',12);

%========================(3)3D PATTERWN====================
%(3)3D Pattern for dipole antenna .
figure
[theta ,phi]=meshgrid(theta,phi);
x=abs(AF).*sin(theta).*cos(phi);
y=abs(AF).*sin(theta).*sin(phi);
z=abs(AF).*cos(theta);
surf(x,y,z);
title('3D  pattern of DOLPH CHEBESHEV ARRAY');
shading flat;

