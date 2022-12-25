#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i , mat1[3][3] , mat2[3][3] , result[3][3];
    int *ptr1=mat1 , *ptr2=mat2 , *ptr3=result ;

    printf("Enter 1st matrix:\n");
     for (i = 0; i<3*3 ; i++)
       scanf("%d",ptr1+i);

    printf("Enter 2nd matrix:\n");
     for (i = 0; i<3*3 ; i++)
       scanf("%d",ptr2+i);

    for (i = 0; i<3*3 ; i++)
       *(ptr3+i) =*(ptr1+i)+*(ptr2+i);

    printf("Result matrix:\n");
   for(i = 0; i<3*3 ; i++)
   {
        printf("%d\t",*(ptr3+i));
        if((i+1)%3==0)
            printf("\n");
   }
    return 0;
}
