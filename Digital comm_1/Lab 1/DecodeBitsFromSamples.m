function rec_bit_seq = DecodeBitsFromSamples(rec_sample_seq,case_type,fs)
%
% Inputs:
%   rec_sample_seq: The input sample sequence to the channel
%   case_type:      The sampling frequency used to generate the sample sequence
%   fs:             The bit flipping probability
% Outputs:
%   rec_sample_seq: The sequence of sample sequence after passing through the channel
%
% This function takes the sample sequence after passing through the
% channel, and decodes from it the sequence of bits based on the considered
% case and the sampling frequence

if (nargin <= 2)
    fs = 1;    %----------> independeent so i will work bit-by-bit of data.
end

switch case_type
    
    case 'part_1'
        %%% WRITE YOUR CODE FOR PART 1 HERE
        rec_bit_seq = bitor(rec_sample_seq,0) ;
        %%%
    case 'part_2'
        %%% WRITE YOUR CODE FOR PART 2 HERE
        i = 1;
        nemofzero = 0;    %here we count num of zeros.
        fs=5;
        while(i <= length(rec_sample_seq))
           i = i+1;  
             if (rec_sample_seq(i-1) == 0)
               nemofzero=nemofzero+1;
             end
          
           if(mod(i,fs) == 0)
            if (nemofzero >= fs / 2)
                rec_bit_seq(i) = 0;
            else
                rec_bit_seq(i) = 1;
            end
            nemofzero =0;
           end
          
        end
        %%%
    case 'part_3'
        %%% WRITE YOUR CODE FOR PART 3 HERE
        fs=5;
        k = 1;
        for i = 1 : 1 : length(rec_sample_seq)
            if(mod(i,fs) == 0)     %---here i check only last bit of each sample (5-10-15......) .
                rec_bit_seq(1,k) = rec_sample_seq(1,i);
                k = k + 1;
            end
        end
        %%%
end