#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int x;
int count;
//int element;
// Two glboal variables to store address of front and rear nodes.
struct Node* front = NULL;
struct Node* rear = NULL;

// To Enqueue an integer
void Enqueue(int x) {
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data =x;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    else
    rear->next = temp;
    rear = temp;
}

// To Dequeue an integer.
void Dequeue(int x) {
    struct Node* temp = front;
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
}

int Front() {
    return front->data;
}

void Print() {
    struct Node* temp = front;
    while(temp != NULL) {
        printf("%d",temp->data);
        temp = temp->next;
        count =temp;
        if (count!=NULL)
         printf(",");
    }
    printf("\n");
}

int main(){
    /* Drive code to test the implementation. */
    // Printing elements in Queue after each Enqueue or Dequeue
int q=0;
  scanf("%d",&q);
  for(int i=0;i<q;i++)
    {
        int  choice=0;
        scanf("%d",&choice);

        if(choice==1)
        {
          scanf("%d",&x);
          Enqueue(x);
        }

        if(choice==2)
          {
           Dequeue(x);
          }


        if(choice==3)
            {
          if(front == NULL)
           printf("Empty\n");
         else
          Print();
          }
}
  return 0;
}
