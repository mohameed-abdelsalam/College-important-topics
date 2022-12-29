#include <stdio.h>
#include <stdlib.h>


/************    Lecture code 2 (creating single linked list)  ******************/

struct node
{
    int data ;
    struct node *next;
}*header;


void createList (int n);

int main ()
{
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d",&n);
    createList(n);

    return 0;
}


void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    /* A node is created by allocating memory to a structure */
    newNode=(struct node*)malloc(sizeof(struct node));

    /* If unable to allocate memory for head node */
    if (newNode==NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        printf("Enter the data of node 1: ") ;
        scanf("%d",&data);

    newNode->data=data;
    newNode->next=NULL;
    header=newNode;
    temp=newNode;

   for(i=2;i<=n;i++)
     {
      /* A newNode is created by allocating memory */
      newNode= (struct node*)malloc(sizeof(struct node));

        if(newNode==NULL)
        {
             printf("Unable to allocate memory.");
             break;
        }
        else
         {
            printf("Enter the data of node (%d): ", i);
            scanf("%d", &data);

            newNode->data=data;
            newNode->next=NULL;

            temp->next=newNode;
            temp=temp->next;

         }
      }

    }
}
