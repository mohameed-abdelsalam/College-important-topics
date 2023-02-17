function JPEGRes = QuantJPEG(splitDCT,DCTQ,scaling)
T=scaling*DCTQ;
[l m row col]=size(splitDCT);

for i=1:row
    for j=1:col
        subIm=double(splitDCT(:,:,i,j));
        JPEGRes(:,:,i,j) =round(subIm./T);
    end
end
end

