function blockDCT = DCTBlock(splits,C8,paramter)

[l m row col]=size(splits);
if paramter~=0
    C8=C8';
end

for i=1:row
    for j=1:col
        subIm=double(splits(:,:,i,j));
        blockDCT(:,:,i,j) =C8*subIm*C8';
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         if paramter==0
%             blockDCT(:,:,i,j) =C8*subIm*C8';
%         else
%             blockDCT(:,:,i,j) =C8'*subIm*C8;
%         end
    end
end
end

