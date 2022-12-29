#include<stdio.h>
#include<stdlib.h>
int dublicat[100];
int x=0;
//======================== this code to put the tree in level order
struct tree
{
    int data ;
    struct tree* left ;
    struct tree* right;
};

struct node *queue[1000];
int front=0;
int rear=0;

void enqueue(struct node *tree)
{
    queue[rear]=tree;
    rear++;
}

struct node *dequeue(){
    front++;
    return queue[front-1];
}

struct tree *buildtree(int numbers[],int n)
{
struct tree *root;
int index=0;
root=malloc (sizeof(struct tree));
root->data=numbers[index];
root->right=NULL;
root->left=NULL;
enqueue(root);
index++;
while(index<n)
    {
     struct tree* current=dequeue();
  if (index<n&&numbers[index]!=-1)
  {
    struct tree*temp=malloc(sizeof(struct tree));
    temp->data=numbers[index];
    temp->right=NULL;
    temp->left=NULL;
    current->left=temp;
    enqueue(temp);

  }
    if( index+1 < n && numbers[index+1] != -1)
        {
         struct tree *temp=malloc(sizeof(struct tree));
         temp->data=numbers[index+1];
         temp->right=NULL;
         temp->left=NULL;
        current->right=temp;
        enqueue(temp);
        }
    index+=2;
    }

return root;

}
//====================================================== end of code that put tree in level order
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        {
         scanf("%d",&arr[i]);
        }

    struct tree* root = buildtree(arr,n);
    inorder(root);
    int h;
    h=x;
   /* for(int i=0;i<h;i++)
        {

            printf("%d\n",dublicat[i]);
        }*/
       checkdublicate(h);
    return 0;
}

//============================================this code to find dublicates and put them in duplicate array
int cur = 1, mx = 0;
struct tree* previous = NULL;

void inorder(struct tree* root)
{

    if (root == NULL) {
        return;
    }
    inorder(root->left);
    if (previous != NULL) {

        if (root->data == previous->data)
        {

            dublicat[x]=root->data;
            x++;
            cur++;
        }
        else {
            cur = 1;
        }
    }

    if (cur > mx)
    {
        mx = cur;
    }

    previous = root;
    inorder(root->right);
}

void checkdublicate(int h)
{
  int counter[100]={0};

  for(int i=0;i<h;i++)
    {
        counter[i]+=2;
        for(int j=i+1;j<h;j++)
            {
             if(dublicat[j]==dublicat[i])
            {
              counter[i]++;
            }
            else{break;}
    }

    }
/*for (int k=0;k<h;k++)
    {
      printf("%d ",counter[k]);
    }*/
    //===================
int max=largest(counter, h);
for(int c=0;c<x;c++)
    {
     if(counter[c]==max)
        {
         printf("%d\n",dublicat[c]);
        }
    }

}

int largest(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
            return max;
}
