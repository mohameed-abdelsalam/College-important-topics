#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int i,j;
    struct node *next;
}*headerMat1,*headerMat2;

void creat(int n,int m,int mat[n][m],int numOfMat)
{
    int i,j,check=0;
    struct node *header ,*newNode, *temp;

`

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


void mult(int n,int k)
{
    int multi[n][k],i,j;
    struct node * tempMat1,*tempMat2;
    tempMat1 = headerMat1;
    tempMat2 = headerMat2;

    for (i = 0;i < n;i++)
    {
        for (j = 0; j < k; j++)
            multi[i][j] = 0;
    }

    while(tempMat1!= NULL)
        {
            tempMat2 = headerMat2;
            while(tempMat2!= NULL)
            {
                if(tempMat1->j==tempMat2->j)
                {
                    multi[tempMat1->i][tempMat2->i] += tempMat1->data*tempMat2->data;
                }
                tempMat2 = tempMat2->next;
            }
            tempMat1 = tempMat1->next;
        }
    for(i=0;i<n;i++)
    {
         for(j=0;j<k;j++)
            printf("%d ",multi[i][j]);
        printf("\n");
     }
}

void free_signal(struct node * header)
{
    struct node *temp;

    temp = header;

    while(temp!=NULL)
    {
        header= header->next;
        free(temp);
        temp = header;
    }


int main()
{
    int i,j,row,column,data;
    int n,m;
    scanf("%d %d",&n,&m);
    int mat1[n][m];


    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&mat1[i][j]);
    }
    int k,q;
    scanf("%d %d",&k,&q);
    int mat2[k][q],transpose[q][k];

    for(i=0;i<k;i++)
    {
        for(j=0;j<q;j++)
            scanf("%d",&mat2[i][j]);
    }


    if(m==k)
    {

        for (i = 0;i < k;i++)
        {
            for (j = 0; j < q; j++)
            {
                transpose[j][i] = mat2[i][j];
            }
        }

        creat(n,m,mat1,1);
        creat(q,k,transpose,2);
        mult(n,k);


    }
    else
    {
        printf("Not valid");
    }

}
