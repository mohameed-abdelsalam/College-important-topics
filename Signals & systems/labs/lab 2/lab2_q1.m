%question 1 :
y1=ones(1,200)*4;
t=linspace(0,1,100);
y2=cos(2*pi*t/4);
y3=ones(1,200)*3;
tnew=[linspace(-2,0,200) t  linspace(1,3,200)];
y=[y1 y2+3 y3];
figure(1);plot(tnew,y);