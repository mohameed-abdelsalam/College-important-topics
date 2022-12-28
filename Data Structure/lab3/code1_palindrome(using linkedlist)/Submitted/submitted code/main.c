#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node *next;
}*head,*head2;

void compare_lists();
void reverseList();
void createList (int n);


int main ()
{
    int n;
    int result=0,q,rem;

    scanf("%d",&n);
    createList(n);
    reverseList();

    compare_lists();

    return 0;
}


void createList(int n)
{
    struct node *newNode,*newNode2, *temp,*temp2;
    int data, i,check=0;
    int result=0,q,rem;

    /* A node is created by allocating memory to a structure */


    /* If unable to allocate memory for head node */
    while(n!=0)
    {
        rem=n%10;
        result=result*10+rem;
        n=n/10;

        if(check==0)
        {
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode2=(struct node*)malloc(sizeof(struct node));
            newNode->data=rem;
            newNode2->data=rem;
            newNode->next=NULL;
            newNode2->next=NULL;
            head=newNode;
            head2=newNode2;
            temp=newNode;
            temp2=newNode2;
            check++;
        }
        else
        {

          /* A newNode is created by allocating memory */
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode2=(struct node*)malloc(sizeof(struct node));
            newNode->data=rem;
            newNode2->data=rem;
            newNode->next=NULL;
            newNode2->next=NULL;

            temp->next=newNode;
            temp = temp->next;
            temp2->next=newNode2;
            temp2=temp2->next;

        }
    }
}


void reverseList()
{
    struct node *prevNode, *currNode;
    if(head2 != NULL)
    {
        prevNode = head2;
        currNode = head2->next;
        head2 = head2->next;

        prevNode->next = NULL;     //Makes the first node as last node

        while(head2 != NULL)
        {
            head2 = head2->next;
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = head2;
        }

        head2 = prevNode;
    }
}

void compare_lists() {
    struct node *l1 = head;
    struct node *l2 = head2;
    while(l1!=NULL)
    {
        if(l1->data!=l2->data)
            break;
        l1=l1->next;
        l2=l2->next;
    }

    if(l1==NULL)
        printf("YES");
    else
        printf("NO");
}

