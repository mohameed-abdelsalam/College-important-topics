clear all
clc 
close all
%Intro to Digital communication Lab 2 
%Part 2
%%%%%%%%%%%% generation of Transmitted symbols (BPSK) %%%%%%%%%%%%%
%%
L = 2000;     %No of bits in seqence A
X_Tx = [];  
X_Tx = randi([0 1],[L 1]);   % sequence of generated bits .
A=length(X_Tx); 
for i= 1 : A 
    if X_Tx(i) == 0
        X_Tx(i)= -1;
    end
end
%%
%%%%%%%%%%%% generation Matrix of channel coeffients %%%%%%%%%%%%%

coeff=MultipathChannel(L,1);
H= zeros(L,L);
for i =1:L
    for j = i:L
        H(j,i) = coeff(j - i +1);
    end 
end 
V = H * X_Tx ;
Eb_No_db = 0;       % The specified Eb/No value in dB
Energy_per_bit=1;
No=Energy_per_bit/( 10^(Eb_No_db/10) );
noise= randn(size(V))*sqrt(No/2); %generate Noise
Y = (H * X_Tx) + noise ; %getting the received signal Y
%%
%%%%%%%%%%%% Estimation of transmitted signal from Received signal %%%%%%%%%%%%%
Z= inv(H); %Equalize channel effect
X = Z * Y;  %Received X from Y
X_Estimated =[]; 
%Decision Maker 
for i=1:A
    if X(i) > 0
        B =1; 
    else
        B=-1;
    end
    X_Estimated =[X_Estimated ; B];   %Estimated_Transmitted_signal
end
%Calculation of BER between transmitted symbols & estimated signal when
%variance = 1
BER = ComputeBER(X_Tx, X_Estimated);
%%
%%%%%%%%%%%% Estimation of BER vs Eb/No %%%%%%%%%%%%%
Eb_No_dB_vector = -15:0;
BER1=zeros(size(Eb_No_dB_vector));

for i= 1:length(Eb_No_dB_vector)
    
No=Energy_per_bit/( 10^(Eb_No_dB_vector(i)/10) );
noise= randn(size(V))*sqrt(No/2);
Y = (H * X_Tx) + noise ;
Z= inv(H);
X= Z * Y;
X_Estimated =[];
for j=1:A
    if X(j) > 0
        B =1; 
    else
        B =-1;
    end
X_Estimated =[X_Estimated ; B];
end
BER1(i) = ComputeBER(X_Tx, X_Estimated);
end
%Plotting BER vs Eb/No
figure
semilogy(Eb_No_dB_vector,BER1,'-xk','linewidth',2)
xlabel('Eb/No','linewidth',2)
ylabel('BER','linewidth',2)

function [h] = MultipathChannel(L,N)

% How to use:
%
% h = MultipathChannel(L) - generates a vector h of length Lx1 containing L
% channel coefficients for the L paths
% h = MultipathChannel(L) - generates a matrix h of dimention LxN, where
% each column corresponds to L channel coefficients for L paths

if nargin < 2
    N = 1;
end

h = randn(L,N) + 1i*randn(L,N);

power_profile = exp(-0.5*[0:L-1])';

power_profile = repmat(power_profile,1,N);

h = abs(h).*power_profile;
end