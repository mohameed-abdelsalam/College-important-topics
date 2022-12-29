#include<stdio.h>

void convert(int X,int N){
    int rem=0;
    if(!X)
        return;
    else {
        rem=X%N;
        convert(X/N,N);
         }
    if(rem>9)
        printf("%c",'A'+(rem-10));
    else
        printf("%d",rem);
    }

int main()
{
    int k=0,w=0;
    scanf("%d",&k);
    scanf("%d",&w);
    convert(k,w);
    return 0;
}
