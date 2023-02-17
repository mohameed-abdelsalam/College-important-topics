function bit_seq = GenerateBits(N_bits)
%
% Inputs:
%   N_bits:     Number of bits in the sequence
% Outputs:
%   bit_seq:    The sequence of generated bits
%
% This function generates a sequence of bits with length equal to N_bits

bit_seq = zeros(1,N_bits);
%%% WRITE YOUR CODE HERE
 X = randperm(N_bits); % create random vector to be used .
 bit_seq(X(1:5000))=1; % Put 5000 ones in random position & [5000:1000]=0 .
%%%