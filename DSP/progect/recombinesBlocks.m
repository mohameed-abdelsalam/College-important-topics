function JPEGImage =  recombinesBlocks(resIDCT)
blockSize=8;

[l m row col]=size(resIDCT);
for i =1:row
    for j=1:col
        JPEGImage( (((i-1)*blockSize)+1) :(i*blockSize) ,(((j-1)*blockSize)+1):(j*blockSize) )=resIDCT(:,:,i,j); 
    end
end

JPEGImage=uint8(JPEGImage);
end

