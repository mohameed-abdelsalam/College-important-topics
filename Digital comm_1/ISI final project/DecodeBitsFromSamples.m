function rec_bit_seq = DecodeBitsFromSamples(rec_sample_seq,fs)
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
    fs = 1;
        count=1;
        for i=1:5:length(rec_sample_seq)
           array=rec_sample_seq(i:i+4);
           if (sum(array)>=3)
          rec_bit_seq(count) = 1;
          else rec_bit_seq(count) = 0;
          end
           count=count+1;
        end
end