#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void freq(int arr[],int len)
{
   int count=0,count_digit=0;
   int *digit_num;
   digit_num=malloc(len*sizeof(int));
   for(int i=0;i<len;i++)
   {
       count=0;
       int l=arr[i];
       while(l>0)
       {
           l/=10;
           count++;
       }
       digit_num[i]=count;
       if(count>count_digit)
        count_digit=count+1;
   }

   int new_element;
   for(int i=0;i<len;i++)
   {
    new_element=arr[i];
    int count_new=digit_num[i];
    while(count_new<count_digit)
    {
        new_element=new_element*pow(10,digit_num[i])+arr[i];
        count_new=0;
        int new_element_1=new_element;
        while(new_element_1>0)
        {
            new_element_1/=10;
            count_new++;
        }
    }
    while(count_new>count_digit)
    {
        new_element/=10;
        count_new--;
    }
    arr[i]=new_element;
   }


    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
   // free(digit_num);
}




int main()
{
    int arr[]={11111,34,3,98,9,76,45,4,12,121};
    int len=sizeof(arr)/sizeof(int);
    freq(arr,len);
    return 0;
}
