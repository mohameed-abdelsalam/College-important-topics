%question 3 :
B=[500 2000 3000 4500];
t=linspace(0,100/5000,100);
n=linspace(0,100,101);
for i=1:1:4;
    f=B(i);
   % Pn=sin(2*(1/5000)*pi*f*n);
    Xt=sin(2*pi*f*t);
%     x=p(1:1:100);
    subplot(2,2,i);
    stem(t,Xt);
%     stem(n,Pn);
    title("plot "+string(i))
end
t2=linspace(0,100/50000,100);
a=2000;
y=sin(2*pi*a*t2);
figure;
stem(t2,y);
title("Y")
% y=sin(2*pi*a*t3);
% figure;
% stem(t3,y);
% t4=linspace(0,(2*10^(-3)),50)0
% figure;
% stem(t4,y);