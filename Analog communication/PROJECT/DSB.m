% We plot the signal in time domain by green & in frequency domain by blue
%______________________DSB____________________
%1.1-read audio
[y,fs]=audioread('eric.wav');
TS=1/fs;
%plot signal in time domain
subplot 211;
plot(real(y),'g');
title('time domain',"Color",'r');
len=length(y);
xdft=fftshift(fft(y));

freq = linspace(-fs/2,fs/2,len);
%plot signal in freq domain
subplot 212;
plot(freq,abs(xdft));
title('in freq domain',"Color",'r');
xlim([-1.5 1.5].*10^4);
figure;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%end of 1.1

%ideal filter
samplePerFreq = len/fs; %number of freq per second
idealLPF =[zeros(round(samplePerFreq*20000),1)
    ;ones(round(samplePerFreq*8000)+1,1);zeros(round(samplePerFreq*20000),1)];
sigAfterLPF=xdft.*idealLPF;  %signal after LPF

dataoffilter=ifft(ifftshift(sigAfterLPF));
%%%1.3-the filtered signal in time domain and frequency domain&1.4-play sound
%sound(real(dataoffilter),fs); %1.4
%pause(samplePerFreq);%1.4

subplot 211;
plot(real(dataoffilter),'g');
title('The filtered signal in time domain',"Color",'r');
subplot 212;
plot(freq,abs(sigAfterLPF));
title('The filtered signal in frequency domain',"Color",'r');
xlim([-4.5 4.5].*10^3)
figure;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%1.5Obtain the SSB by filtering out the USB (we need to get LSB only) of the DSB-SC modulated signal using an ideal filter

FC =100*1000;   %carrier freq
fs2=5*FC;       %new sampling freq of message signal   

dataoffilter_up=resample(dataoffilter,fs2,fs);  % upsampling  
t =linspace(0,length(dataoffilter_up)*1/fs2,length(dataoffilter_up)); % resize cosine same size as signal 

carrier=cos(2*pi*FC*t);
carrier=carrier';%transpose carrier to fit the input signal

A=2*max(dataoffilter_up);%Modulation index = .5

freqUp =linspace(fs2/2,-fs2/2,length(dataoffilter_up));

DSB_SC= dataoffilter_up.*carrier; % modulated signal s(t) in time
DSB_SCinFreq = fftshift(fft(DSB_SC)); % modulated signal s(t) in freq

subplot 211;
plot(freqUp,abs(DSB_SCinFreq));%Title is a comment:)
title('Modulated signal of DSB-SC in frequency domain.',"Color",'r');
xlim([-11 11].*10^4)

DSB_TC=(A+dataoffilter_up).*carrier;
DSB_TCinFreq = fftshift(fft(DSB_TC));

subplot 212;
plot(freqUp,abs(DSB_TCinFreq));%Title is a comment:)
title('Modulated signal of DSB-TC in frequency domain.',"Color",'r');
xlim([-11 11].*10^4)
figure;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%end of 1.5

%%%%1.6&1.7-Envlope detection 
envlope_SC=abs(hilbert(real(DSB_SC)));
envlope_SCdown=resample(envlope_SC,fs,fs2); %downsampling
envlope_TC=abs(hilbert(real(DSB_TC)));
envlope_TCdown=resample(envlope_TC,fs,fs2); %downsampling
envlope_TCdown =envlope_TCdown(1:end-1);

%we know that the envolpe can't be used with DSB-SC so the out put is a distortion
subplot 211;
plot(real(envlope_SCdown),'g')%Title is a comment:)
title('Envlope of DSP-SC in time',"Color",'r');
%sound(real(envlope_SCdown),fs);
%pause(samplePerFreq);
%audiowrite("ScMod.wav",envlope_SCdown,fs);

subplot 212;
plot(real(envlope_TCdown),'g');%Title is a comment:)
title('Envlope of DSP-TC in time ',"Color",'r');
figure;

%sound(real(envlope_TCdown),fs)
%pause(samplePerFreq);
%From sounds, we prove that the envlope detection can't not be use in DSB-SC,but use in DSB-TC in case of m<1
%audiowrite("TcMod.wav",envlope_TCdown,fs);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%end of 1.6&&1.7    

%%%%%%%%1.8-coherent detection

%Add additive white gaussian noise
noisedSig_30 = awgn(DSB_SC,30,'measured');
noisedSig_10 = awgn(DSB_SC,10,'measured');
noisedSig_0 = awgn(DSB_SC,0,'measured');

%noisedSig =resample(noisedSig,fs,fs2);
%%%%%%%%%%%%%%%%%%%%1.9-frequency error&1.10- phase error
fError = .1*1000;
carrierfreqEr =cos(2*pi*(FC+fError)*t)'; %%Beat effect
phaseError = 20;
carrierPhaseEr =cos(2*pi*FC*t+pi*phaseError/180)';
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%1.9&1.10

cohNoError = 2*noisedSig_30.*carrierPhaseEr; %%chose SNR & carrier 
cohNoError = resample(cohNoError,fs,fs2); %down sample
%%This beacause after resample lenght of signal increase by 1 so we ignore last element
cohNoError = cohNoError(1:end-1);
cohFFT = fftshift(fft(cohNoError));
cohFFT = idealLPF.*cohFFT;
cohtime = ifft(ifftshift(cohFFT)) ;

sound(real(cohtime),fs)

subplot 211;
plot(real(cohtime),'g');%Title is a comment:)
title('Coherent detection Recived massage in DSP-SC in time-domain(SNR=0)',"Color",'r');

subplot 212;
plot(freq,abs(cohFFT));%Title is a comment:)
title('Coherent detection Recived massage in DSP-SC in frequency-domain(SNR=0)',"Color",'r');
xlim([-4.5 4.5].*10^3)    

