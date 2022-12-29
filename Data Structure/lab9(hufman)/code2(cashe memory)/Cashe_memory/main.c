// A C program to demonstrate linked list based implementation of queue
#include <stdio.h>
#include <stdlib.h>

// A linked list node to store a queue entry
struct QNode {
    int value;
    int key;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

// create a new linked list node.
struct QNode* newNode(int k,int value)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->value=value;
    temp->next = NULL;
    return temp;
}

// function to create an empty queue
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void Enqueue(struct Queue* q, int k,int value)
{
    // Create a new LL node
    struct QNode* temp = newNode(k,value);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    }
    else
    {
        // Add the new node at the end of queue and change rear
        q->rear->next = temp;
        q->rear = temp;

    }
}

// Function to remove a key from given queue q
void deQueue(struct Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

int accessed(struct Queue *q,int key,int param)
{
    struct QNode *pre,*check,*nextNode,*temp=q->front;


    while(temp->next!=NULL&&temp->key!=key)
    {
        if(temp->next->key==key)
            break;
        temp=temp->next;
    }
    check =temp;

    if(check->next==NULL&&check->key!=key)
        return 0;

    if(temp==q->front&&param==0)
        printf("%d\n",temp->value);
    else
    {
        if(temp->next!=NULL)
        {
            if(temp->key==key)
            {
                nextNode=temp->next;
                q->front=nextNode;
                q->rear->next=temp;
                q->rear=temp;
                temp->next=NULL;
                if(param==0)
                    printf("%d\n",temp->value);
                else
                    temp->value=param;
            }
            else if(temp->next==q->rear)
            {
                temp->next->value=param;
            }
            else
            {
                pre=temp;
                temp=temp->next;
                if(temp!=q->rear)
                {
                    nextNode=temp->next;
                    pre->next=nextNode;
                    temp->next=NULL;
                    q->rear->next=temp;
                    q->rear=temp;
                }
                if(param==0)
                    printf("%d\n",temp->value);
                else
                    temp->value=param;
            }
        }
    }
    if(param!=0)
        temp->value=param;

    return 1;

}



void Print(struct Queue *q) {
    struct QNode* temp = q->front;

    while(temp != NULL) {
        printf("%d\t%d\n",temp->key,temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Driver Program to test anove functions
int main()
{
    struct Queue *q;
    int op,data,key,size,count=0,check=1;

    q = createQueue();

    scanf("%d",&op);
    scanf("%d",&size);
    for(int i=0;i<op;i++)
    {
        int  choice=0;
        scanf("%d",&choice);

        if(choice==1)
        {
            scanf("%d",&key);
            scanf("%d",&data);

            if(size==0)
                printf("Error\n");
            else if(size>count)
            {
                if(count!=0)
                    check=accessed(q,key,data);



                if(check==0||count==0)
                {
                    Enqueue(q,key,data);
                    count++;
                }
            }
            else
            {
                deQueue(q);
                Enqueue(q,key,data);

            }
        }

        if(choice==2)
        {
            scanf("%d",&key);
            if(size!=0&&count!=0)
                check =accessed(q,key,0);
            if(check==0||count==0)
                printf("Not Found\n");


        }
        if(choice==3)
            Print(q);
    }
    return 0;
}
