% clc
% clear all
% We plot the signal in time domain by green & in frequency domain by blue
%&phase black
%______________________FM____________________
%read audio
[y,fs]=audioread('eric.wav');
TS=1/fs;

%plot signal in time domain
figure;
subplot 311;
plot(real(y),'g');
title('Input signal in time domain',"Color",'r');
len=length(y);
xdft=fftshift(fft(y));
phaseOfInput= angle(xdft)*(180/pi);%in degree

freq = linspace(-fs/2,fs/2,len);
%plot signal in freq domain
subplot 312;
plot(freq,abs(xdft));
title('Input signal in frequency domain',"Color",'r');
xlim([-1.5 1.5].*10^4);

subplot 313;
plot(freq,phaseOfInput,'k');
title('Input of signal phase',"Color",'r');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%ideal filter
samplePerFreq = len/fs; %number of freq per second
idealLPF =[zeros(round(samplePerFreq*20000),1)
    ;ones(round(samplePerFreq*8000)+1,1);zeros(round(samplePerFreq*20000),1)];
sigAfterLPF=xdft.*idealLPF;  %signal after LPF
phaseOffilter= angle(sigAfterLPF)*(180/pi);%in degree

dataoffilter=ifft(ifftshift(sigAfterLPF));
%%%1.3-the filtered signal in time domain and frequency domain&1.4-play sound

figure;
subplot 311;
plot(real(dataoffilter),'g');
title('The filtered signal in time domain',"Color",'r');
subplot 312;
plot(freq,abs(sigAfterLPF));
title('The filtered signal in frequency domain',"Color",'r');
xlim([-4.5 4.5].*10^3)
subplot 313;
plot(freq,phaseOffilter,'k');
title('The phase of the filtered signal',"Color",'r');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
FC =100*1000;   %carrier freq
fs2=5*FC;       %new sampling freq of message signal   
dataoffilter_up=resample(dataoffilter,fs2,fs); %upsampling  
t =linspace(0,length(dataoffilter_up)*1/fs2,length(dataoffilter_up));        % resize cosine same size as signal 
carrier=cos(2*pi*FC*t);
carrier_shift = sin(2*pi*FC*t);
carrier=transpose(carrier);
carrier_shift =carrier_shift';

%get integration of message
integ = cumsum(dataoffilter_up);

% Defining the approximated version of the modulated signal.
% This is going to cause some noise in the output.
NBFM = carrier - (integ .* carrier_shift);%NFBM equ without K.F
%condition to achieve NBFM BW=2fm

NBFM_infreq = fftshift(fft(NBFM));

%get mag and phase of modulated signal
phaseNBFM_infreq = angle(NBFM_infreq)*(180/pi);%in degree
FreqUP = linspace(-fs2/2,fs2/2,length(NBFM_infreq ));

figure;

subplot 311;
plot(real(NBFM),'g')
title('NBFM Time Domain',"Color",'r');

subplot 312;
plot(FreqUP,abs(NBFM_infreq) )
title('Magnitude of NBFM F_Domain',"Color",'r')
xlim([-1.5 1.5].*10^5)
ylim([0 10000])

subplot 313;
plot(FreqUP,phaseNBFM_infreq,'k');
title('The phase of the filtered signal',"Color",'r');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%demodulation using DIFF and ED (to NFBM in time)
%diff modulated signal

NBFMDemod=abs(hilbert(real(NBFM)));%applay ED
NBFMDemod=diff(NBFMDemod);%diffrentiate
NBFMDemodDown =resample(NBFMDemod,fs,fs2); %downsampling
NBFMDemodInFreq = fftshift(fft(NBFMDemodDown));
NBFMDemodPhase = angle(NBFMDemodInFreq)*(180/pi);%in degree

sound(real(NBFMDemodDown),fs)

figure;
subplot 311;
plot(real(NBFMDemodDown),'g');
title('Recieved message in TIME Domain',"Color",'r');
ylim([-0.2 0.2]);

subplot 312;
plot(freq,abs(NBFMDemodInFreq));
title('Recieved message in Frequency Domain',"Color",'r');
xlim([-4.5 4.5].*10^3);

subplot 313;
plot(freq,NBFMDemodPhase,'k');
title('Recieved message Phase.',"Color",'r');
