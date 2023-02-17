% We plot the signal in time domain by green & in frequency domain by blue
%______________________SSB____________________
%2.1-read audio
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%end of 2.1

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

DSB_SC= dataoffilter_up.*carrier;  % modulated signal s(t) in time
DSB_SCinFreq = fftshift(fft(DSB_SC)); % modulated signal s(t) in freq

freqSSB=linspace(-fs2/2,fs2/2,length(DSB_SCinFreq)); 
subplot 211;
plot(freqSSB,abs(DSB_SCinFreq));%%2.4
title('bofore band pass filter in freq-domain ideal filter',"Color",'r');
xlim([-11 11].*10^4)

%%%%Ideal filter to get LSB
samplePerFreq =length(DSB_SC)/fs2; 

filterBW = (fs2*4000)/fs; %4K in fs !=4K in 5FC but for 4K in 5FC = (5FC*4K)/fs
L1=round(samplePerFreq*150000)+round(samplePerFreq*filterBW)+1; %%%%this is the -4K in case of fs 
U1= round(samplePerFreq*(350000+1))-round(samplePerFreq*filterBW)-1;%%%this is the 100K -4K in case of fs

DSB_SCinFreqIdeal =  DSB_SCinFreq;
%%This like multiply all elements except LSB by zero
DSB_SCinFreqIdeal(1:round(samplePerFreq*(150000-1)))=0;
DSB_SCinFreqIdeal(L1:U1)=0;
DSB_SCinFreqIdeal(round(samplePerFreq*(350000+1)):end)=0;

subplot 212;
plot(freqSSB,abs(DSB_SCinFreqIdeal));%%2.4-sig in f-domain after BPF so it is LSB
title('After band pass filter in freq-domain ideal filter',"Color",'r');
xlim([-11 11].*10^4)
figure;

DSB_SCinTimeIdeal = ifft(ifftshift(DSB_SCinFreqIdeal));
SSB_SC = DSB_SCinTimeIdeal.*carrier;%%demodulation
SSB_SC = resample(SSB_SC,fs,fs2);%%down sampling the sig after demodulation

SSB_SC_ff= fftshift(fft(SSB_SC)) ;

%%%%Ideal LPF to get LSB after demodulation
%%This beacause after resample lenght of signal increase by 1 so we ignore last element
SSB_SC_ff=SSB_SC_ff(1:end-1);  
SSB_SC_ff =SSB_SC_ff.*idealLPF;
SSB_SC_time =ifft(ifftshift(SSB_SC_ff)) ; 
afterDownfreq= ifftshift(fft(SSB_SC_time));

%%sound(real(SSB_SC_time),fs) %2.6

subplot 211;
plot(real(SSB_SC_time),'g');  %2.6-recieved LSB ideal in time-domain no noise
title('recieved LSB ideal in time-domain',"Color",'r');

subplot 212;
plot(freq,abs(afterDownfreq));  %2.6-recieved LSB ideal in freq-domain no noise
title('recieved LSB ideal in freq-domain',"Color",'r');
xlim([-4.5 4.5].*10^3)
figure;

%%2.7-Butterworth filter BPF to get LSB
fnormalized = fs2/2;

%BPF Butterworth to get LSB 
[numerator, denomenator] = butter(4,[FC FC+filterBW]./fnormalized,'bandpass');
DSB_SCFilter = filter(numerator, denomenator, DSB_SC);

subplot 211;
plot(freqSSB,abs(DSB_SCinFreq));%%2.4-sig before BPF
title('Bofore band pass Butterworth in freq-domain ideal filter',"Color",'r');
xlim([-11 11].*10^4)

subplot 212;
plot(freqSSB,abs(fftshift(fft(DSB_SCFilter))));%%2.5-sig before BPF
title('After band pass Butterworth in freq-domain ideal filter',"Color",'r');
xlim([-11 11].*10^4)
figure;


LSBButterfilter = DSB_SCFilter.*carrier;%Demodulation the received signal
LSD_down =resample(LSBButterfilter,fs,fs2);%downSample
%%This beacause after resample lenght of signal increase by 1 so we ignore last element 
LSD_down =LSD_down(1:end-1);

%%Butterworth filter LPF to get LSB after demodulation
[numerator, denomenator] = butter(4,4000/(fs/2));
LSD_downLPFTime = filter(numerator, denomenator, LSD_down);
LSD_downLPFFreq = fftshift(fft(LSD_downLPFTime)); 

sound(real(LSD_downLPFTime),fs) %2.7

subplot 211;
plot(real(LSD_downLPFTime),'g');  %2.7-recieved LSB butter filter in time-domain
title('recieved LSB butter filter in time-domain',"Color",'r');

subplot 212;
plot(freq,abs(LSD_downLPFFreq));%2.7-recieved LSB butter filter in freq-domain
title('recieved LSB butter filter in freq-domain',"Color",'r');
xlim([-4.5 4.5].*10^3)
figure;

%%%%%%%%%%%% ADD noice 
noisedSig_30 = awgn(DSB_SCinTimeIdeal,30,'measured');%SNR=30
noisedSig_10 = awgn(DSB_SCinTimeIdeal,10,'measured');%SNR=10
noisedSig_0 = awgn(DSB_SCinTimeIdeal,0,'measured');  %SNR=0

%noisedSig =resample(noisedSig,fs,fs2);

LSB = 2*noisedSig_0.*carrier;  %%choise SNR 0or10or30 
coherent = resample(LSB,fs,fs2);
%%This beacause after resample lenght of signal increase by 1 so we ignore last element
coherent = coherent(1:end-1);
coherentFreq = fftshift(fft(coherent));
coherentFilter = idealLPF.*coherentFreq;
coherentTime = ifft(ifftshift(coherentFilter)) ;

% sound(real(coherentTime),fs) %2.7


subplot 211;
plot(real(coherentTime),'g');  %2.7-Title is a comment:)
title('recieved LSB butter filter in time-domain-SNR=0',"Color",'r');

subplot 212;
plot(freq,abs(coherentFilter));%2.7-Title is a comment:)
title('recieved LSB butter filter in freq-domain-SNR=0',"Color",'r');
xlim([-4.5 4.5].*10^3)
figure;

%%%%%%%%%%SSB-TC
A=2*max(dataoffilter_up); %Modulation index = .5
SSB_TC=(A+dataoffilter_up).*carrier;

%%% Ideal BPF to get LSB as previous
SSB_TC_freq =  fftshift(fft(SSB_TC));
SSB_SCinFreqIdeal =  SSB_TC_freq;
SSB_SCinFreqIdeal(1:round(samplePerFreq*(150000-1)))=0;
SSB_SCinFreqIdeal(L1:U1)=0;
SSB_SCinFreqIdeal(round(samplePerFreq*(350000+1)):end)=0;

SSB_TC_time = ifft(ifftshift(SSB_SCinFreqIdeal));
%%%%%%Envlope detection
envlopeSSBTC=abs(hilbert(real(SSB_TC_time)));
envlopeSSBTCdown=resample(envlopeSSBTC,fs,fs2); %downsampling
envlopeSSBTCdown = envlopeSSBTCdown(1:end-1);
envlopeSSBTCdown_f = fftshift(fft(envlopeSSBTCdown)) ;

subplot 211;
plot(real(envlopeSSBTCdown),'g');
title('Envlope of SSC-Tc in time domain.');

subplot 212;
plot(freq,abs(envlopeSSBTCdown_f),'g');
title('Envlope of SSC-Tc in frequency domain.');
%sound(real(envlopeSSBTCdown),fs)
