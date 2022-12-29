#include <stdio.h>
#include <stdlib.h>

struct stu
{
    int roll ;
    char name[30];
    int age ;
    struct stu *next;
}header;

int main()
{
    struct stu n1,n2,n3;
    struct stu *p;
    scanf ("%d %s %d", &n1.roll,n1.name, &n1.age);
    scanf ("%d %s %d", &n2.roll,n2.name, &n2.age);
    scanf ("%d %s %d", &n3.roll,n3.name, &n3.age);

    n1.next=&n2;
    n2.next = &n3 ;
    n3.next = NULL ;

    p=&n1;
    while(p!=NULL)
    {
       printf ("\n %d %s %d", p->roll, p->name, p->age);
       p = p->next;
    }
    return 0;
}
