function C8 = findDCTMatrix()
r=[0:7];
K=[1:7]';
u0=sqrt(1/8);
C0=[u0 u0 u0 u0 u0 u0 u0 u0];
C7 = sqrt(2/8).*cos((pi/8)*(K*(r+.5)));
C8 = [C0;C7];
end

