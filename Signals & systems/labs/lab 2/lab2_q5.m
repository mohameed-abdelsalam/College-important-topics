figure(5);
n=linspace(-8,7,16);
x=[1 -2 4 6 -5 8 10];
x1 = 3.*[zeros(1,2) x zeros(1,7)] + [zeros(1,8) x zeros(1,1)] + 2.*[zeros(1,4) x zeros(1,5)];
x2 = [x zeros(1,9)].*[zeros(1,5) x zeros(1,4)] + [zeros(1,8) flip(x)  zeros(1,1)].*[zeros(1,4) x zeros(1,5)];
x3 = zeros(1,16);
for i=1:5
    x3 = x3+n.*[zeros(1,4+i) x zeros(1,5-i)];
end
stem(n,x1);
%stem(n,x1);
title('x1(n)');
figure;
stem(n,x2);
%stem(n,x2);
title('x2(n)');
figure;
stem(n,x3);
%stem(n,x3);
title('x3(n)');