function result = SplitImage(grayImage)

blockSize=8;
[Row Col]=size(grayImage);

for i =1:Row/blockSize
    for j=1:Col/blockSize
        result(:,:,i,j) = grayImage( (((i-1)*blockSize)+1) :(i*blockSize) ,(((j-1)*blockSize)+1):(j*blockSize) );
    end
end
end

