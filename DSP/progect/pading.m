function padGray = pading(grayIm)

[row colum]=size(grayIm);
padrow=0;
padclo=0;
if(mod(row,8))
    num=floor(row/8)+1;
    padrow=num*8-row;
end
if(mod(colum,8))
    num=floor(colum/8)+1;
    padclo=num*8-colum;
end
if((mod(colum,8))&(mod(row,8)))
   padGray= padarray(grayIm,[padrow padclo],0,'post');
else
   padGray=grayIm;
end
end