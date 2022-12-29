#include<stdio.h>
typedef struct que
{
    int info,prio;
    struct que *next;
}nodetype;
void insert(nodetype**,nodetype**,int,int);
void display(nodetype*);


int  main()
{
   nodetype *front=NULL,*rear=NULL;

    int num_of_op;
    scanf("%d",&num_of_op);
    while(num_of_op--)
    {
        int info,prio;
        scanf("%d%d",&info,&prio);
        insert(&front,&rear,info,prio);
    }
    if(front==NULL)
         printf("\nNo elements in the Priority Queue");
    else
       display(front);

    return 0;
}
void insert(nodetype **front,nodetype **rear,int num,int pr)
{
    nodetype *p=NULL,*tmp=*front;
    p=(nodetype*)malloc(sizeof(nodetype));
    if(p!=NULL)
    {
         p->info=num;
         p->prio=pr;
         p->next=NULL;
    }
    if((*rear)==NULL)
    {
         (*front)=(*rear)=p;
    }
    else
    {
         if((p->prio)>=((*rear)->prio))
         {
              (*rear)->next=p;
              (*rear)=p;
         }
         else if(p->prio<((*front)->prio))
         {
              p->next=(*front);
              (*front)=p;
         }
         else
         {
              while(((tmp->next)->prio)<(p->prio))
              tmp=tmp->next;
              p->next=tmp->next;
              tmp->next=p;
         }
    }
}

void display(nodetype *front)
{
    int count1=0,count2=0;
    nodetype *tmp;
    tmp=front;
    while(tmp!=NULL)
    {
         if(tmp->prio>count1)
         {
             count1+=tmp->info;
             count2++;
             //printf("%d %d",tmp->info,tmp->prio);
             tmp=tmp->next;
         }
         else  break;
    }
    printf("%d ",count2);
}
