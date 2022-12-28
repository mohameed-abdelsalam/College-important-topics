#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,Q,i,j;
    //printf("enter N & Q : \n");
    scanf("%d %d",&N,&Q);
    //printf("%d  %d\n",N,Q);

    unsigned int h[N],t[Q];

    //printf("enter developers hours \n");
    for (i=0 ; i < N ;i++ )
    {
        scanf("%d",&h[i]);
    }
    //printf("enter tasks duration \n");
    for ( i=0 ; i < Q ; i++)
    {
        scanf("%d",&t[i]);
    }
/*printf("original list \n");
    for ( i=0 ; i < N ; i++ )
    {
        printf("%d\t",h[i]);
    }
*/
while(1)
{
    int check=0;
    for(i=0 ;i < N-1; i++)   //(N-1) Cause swap save me 1 itrarion when (N-1) last swap happened.
    {
        if (h[i]>h[i+1])
        {
            int temp = h[i];
            h[i] = h[i+1];
            h[i+1]=temp;

            check=1;
        }
    }

    if(check==0)  //This means list is empty.
        break;
}
while(1)
{
    int check=0;
    for(i=0 ;i < Q-1; i++)   //(N-1) Cause swap save me 1 itrarion when (N-1) last swap happened.
    {
        if (t[i]>t[i+1])
        {
            int temp = t[i];
            t[i] = t[i+1];
            t[i+1]=temp;

            check=1;
        }
    }

    if(check==0)  //This means list is empty.
        break;
}

/*printf("\nsorted list\n");
for(i=0 ;i < N; i++)
    printf("%d \n",h[i]);

printf("\nsorted list\n");
for(i=0 ;i < Q; i++){
    printf("%d \n",t[i]);
    }
*/

    int counter = 0;
    for(i=0;i<N;i++)
    {
        for (j=0;j<Q;j++)
        {
            if(h[i]>=t[j])
            {
                counter++;
                t[j]=4000000000;
                j=1000;

            }
        }
    }

printf("%d",counter);

    return 0;
}
