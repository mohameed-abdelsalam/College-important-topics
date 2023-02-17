function rescaleIm =  rescaling(QuntBlock,scaling,DCTQ)
T=scaling*DCTQ;

[l m row col]=size(QuntBlock);

for i=1:row
    for j=1:col
        subIm=double(QuntBlock(:,:,i,j));
        rescaleIm(:,:,i,j) =subIm.*T;
    end
end
end

