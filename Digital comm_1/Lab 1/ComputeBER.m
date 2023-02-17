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

%%% WRITE YOUR CODE HERE
BER= biterr(bit_seq,rec_bit_seq);
%%%
%number_error = biterr(bit_seq,rec_bit_seq); 
%BER=(number_error)/length(bit_seq);         -------> BRE=#Errors/total bits