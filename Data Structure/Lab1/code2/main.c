#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sal=0,gross=0,counter=0;
    int i,sales_people[9]={0};

    while(gross!=-1)
    {
        printf("Enter gross (-1 to end) : ");
        scanf("%d",&gross);
        if (gross==-1)
            break;
        sal = 200+(gross*9)/100;
        printf("your salary is %d\n",sal);
        if (sal>=200&&sal<300)
            sales_people[0]+=1;
        else if((sal>=300&&sal<400))
            sales_people[1]+=1;
        else if((sal>=400&&sal<500))
            sales_people[2]+=1;
        else if((sal>=500&&sal<600))
            sales_people[3]+=1;
        else if((sal>=600&&sal<700))
            sales_people[4]+=1;
        else if((sal>=700&&sal<800))
            sales_people[5]+=1;
        else if((sal>=800&&sal<900))
            sales_people[6]+=1;
        else if((sal>=900&&sal<1000))
            sales_people[7]+=1;
        else
            sales_people[8]+=1;

        counter++;

    }

    printf("\nTotal %d Employees Reported\n",counter);
    printf("employees in the range:\n");
    printf("200\t299: %d\n",sales_people[0]);
    printf("300\t399: %d\n",sales_people[1]);
    printf("400\t499: %d\n",sales_people[2]);
    printf("500\t599: %d\n",sales_people[3]);
    printf("600\t699: %d\n",sales_people[4]);
    printf("700\t799: %d\n",sales_people[5]);
    printf("800\t899: %d\n",sales_people[6]);
    printf("900\t999: %d\n",sales_people[7]);
    printf("over 1000: %d\n",sales_people[8]);

    return 0;
}
