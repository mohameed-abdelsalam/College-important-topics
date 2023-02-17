clear all
clc
close all
%Intro to Digital communication Lab 2
%Part 1
%--------------------------------------
%% Basic Parameters
%--------------------------------------
B = 1e5;    %B = bandwidth
T = 2/B;    %Pulse Duration
fs = 1e7;   %Sampling Frequency
Ts = 1/fs;  %Sampling time
N = ((round(T*fs))*50)-1;

%% Section 1
%--------------------------------------
%Generate Pulse Signal

%%%Input Time Domain%%%
bits = ones(1,round(T*fs));
zero = zeros(1,N - length(bits));
sq_pulse1 = [bits zero];
t = (0 : N-1)*Ts;
figure;
plot(t,sq_pulse1)
xlabel('time(sec)')
title('First Rectangular Pulse')
xlim([0 0.4e-4])
ylim([0 1.25])

%%%Input Frequency Domain%%%
sq_pul_f = (fftshift(fft(sq_pulse1)));
f = linspace(-fs/2 , fs/2 , N);
figure;
plot(f,(abs(sq_pul_f)))
xlabel('frequency(Hz)')
title('Rectangular Pulse')
xlim([-4*B 4*B])

%% Section 2
%--------------------------------------
%%%Channel Creation%%%
channel = sq_pul_f;
zeros_p1 = round(N/2) - round(N*(B*Ts));
zeros_p2 = round(N/2) + round(N*(B*Ts));
channel([1:(zeros_p1) (zeros_p2):end])=0;
channel([(zeros_p1):(zeros_p2)]) = 1;
figure;
plot(f,channel)
xlabel('frequency(Hz)')
title('Band Limited channel')
xlim([-1.5*B 1.5*B])

%% Section 3 
%--------------------------------------
%%%Output of the Channel%%%
out1_f = sq_pul_f.*channel;

%%%Output Frequecny Domain%%%
figure;
plot(f,abs(out1_f))
xlabel('frequency(Hz)')
title('Output of single pulse in "frequency"')
xlim([-1.25*B 1.25*B])


%%%Output Time Domain%%%
out1 = ifft(ifftshift(out1_f));
figure;
plot(t,out1)
xlabel('time(sec)')
title('Output of single pulse in "time"')
xlim([0 0.4e-4])

%% Section 4
%-------------------------------------
sq_pulse2 = circshift(sq_pulse1,round(T*fs));
sq_pul_f2 = fftshift(fft(sq_pulse2));
figure;
plot(t,sq_pulse2)
xlabel('frequency(Hz)')
title('Second Rectangular Pulse in "frequency"')
xlim([0 0.4e-4])
figure;
plot(t,sq_pulse1)
hold on
plot(t,sq_pulse2,'r')
xlabel('time(sec)')
title('ISI of two pulses in "time"')
xlim([0 0.8e-4])


%% Section 5
%-------------------------------------
%%%Output Frequecny Domain%%%
out2_f = sq_pul_f2.*channel;
figure;
plot(f,out1_f)
hold on
plot(f,out2_f,'r')
xlabel('frequency(Hz)')
title('ISI of Output  in "frequency"')
xlim([-1.25*B 1.25*B])


%%%Output Time Domain%%%
out2 = ifft(ifftshift(out2_f));
sum_2_pulses = out1 + out2;
figure;
plot(t,out1)
hold on
plot(t,out2,'r')
hold on
plot(t,sum_2_pulses,'-.','color',[0 1 0])
xlabel('time(sec)')
title('ISI of Output in "time"')
xlim([0 1e-4])

%% Section 6
%-------------------------------------
%No ISI (Cancellation)

t=linspace(-8e-4,8e-4,1000);
x1=sinc((5e3)*t);
figure;plot(t,x1);
title('Sinc Function Generation');
xlabel('time(sec)');
grid on
x2=sinc((5e3)*(t-2e-4));
hold on;plot(t,x2,'r');

%% Section 7
%-------------------------------------
N= 5;
Deltas = randi([0 1],1,N); %random sequence of deltas
R=0;
Pulses = repelem(Deltas,100); %Forming Pulses of BW = 100 
Noised= awgn(Pulses,10);
figure;
plot(Noised);title('Pulse shape with AWGN');grid on
counter=1;
for X=50:100:N*100  
    if Noised(X) > 0.5 
        R(counter)=1;
    elseif Noised(X) < 0.5
        R(counter)=0;
    end
    counter=counter+1;
end
error = numel(find(R ~= Deltas));
BER = error/N;
