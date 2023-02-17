function BER = ComputeBER(bit_seq,rec_bit_seq)
%
% Inputs:
%   bit_seq:     The input bit sequence
%   rec_bit_seq: The output bit sequence
% Outputs:
%   BER:         Computed BER
%
% This function takes the input and output bit sequences and computes the
% BER


%   E:           number of error bits
E = 0;
for i=1:length(rec_bit_seq)
    if rec_bit_seq(i) ~= bit_seq(i)
        
        E = E + 1 ;
       
    end
end

BER = E/length(bit_seq);
%%%
E = 0;