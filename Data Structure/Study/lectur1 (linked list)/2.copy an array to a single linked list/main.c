#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 		          //Data part
    struct node *next;        //Address part
};

int main()
{
    struct node *header, *newNode, *temp;
    int data, i,j, n, a[100];
    printf("Enter the total number of data: ");
    scanf("%d", &n);



   for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]!=0)
            {
                if(check==0)  //this condition is to get only one time at first node then skip to 2nd created node an so on.
                {
                    newNode = (struct node *)malloc(sizeof(struct node));

                    newNode->data = mat[i][j];
                    newNode->i = i;
                    newNode->j = j;
                    newNode->next = NULL;
                    temp = newNode;
                    check=1;
                }
                else
                {

                    newNode = (struct node *)malloc(sizeof(struct node));

                    newNode->data = mat[i][j];
                    newNode->i = i;
                    newNode->j = j;
                    newNode->next = NULL;
                    temp->next = newNode;
                    temp = newNode;

                }
            }
        }
    }
}



    // Write code here to initialize the array a with n elements //
    /* A node is created by allocating memory to a structure */
    newNode = (struct node *)malloc(sizeof(struct node));

    /* If unable to allocate memory for head node */
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = a[0]; //Links the data field with data
        newNode->next = NULL; //Links the address field to NULL
        header = newNode;     //Header points to the first node
        temp = header;

    for(i = 1; i <= n; i++)
    {
      /* A newNode is created by allocating memory */
      newNode = (struct node *)malloc(sizeof(struct node));

      if(newNode == NULL)
      {
         printf("Unable to allocate memory.");
         break;
      }
      else
      {
         newNode->data = a[i]; //Links the data field of newNode with a[i]
         newNode->next = NULL; //Links the address field of newNode with NULL

         temp->next = newNode; //Links previous node i.e. temp to the newNode
         temp = temp->next;
       }
     }
   }
}
