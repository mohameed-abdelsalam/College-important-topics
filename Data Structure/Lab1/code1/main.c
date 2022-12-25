#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num[5] , pos_sum=0 , neg_sum =0 , pos_average , neg_average;
    int i , pos_counter=0 , neg_counter=0 ;

    printf("ENTER THE 5 NUMERS \n ");
    for(i=0; i<5 ;i++)
         scanf("%f",&num[i]);

 for(i=0; i<5 ;i++)
{
      if (num[i]>= 0){
        pos_counter++ ;
        pos_sum+=num[i];
      }
      else {
        neg_counter++ ;
        neg_sum+=num[i];
      }
 }

if(pos_counter!=0)
    pos_average = pos_sum / pos_counter ;
else
    pos_average=0;

if(neg_counter!=0)
    neg_average = neg_sum / neg_counter ;
else
    neg_average=0;

  printf ("\nNumber of positive numbers :%d",pos_counter);
  printf ("\nNumber of negative numbers :%d",neg_counter);
  printf ("\naverage of positive numbers :%.3f",pos_average);
  printf ("\naverage of negative numbers :%.3f",neg_average);
    return 0;
}
