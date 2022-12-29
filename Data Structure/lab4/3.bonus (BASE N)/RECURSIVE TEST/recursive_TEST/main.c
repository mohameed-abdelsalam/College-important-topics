#include <stdio.h>

void fun(int x,int y)
{
 if(x==0)
    {
        return;
    }

    else
        {
         fun(x/y,y);
        }

printf("%X",x%y);

}


int main ()
{
int x , y;

scanf("%d",&x);
scanf("%d",&y);
fun(x,y);

return 0;
}
