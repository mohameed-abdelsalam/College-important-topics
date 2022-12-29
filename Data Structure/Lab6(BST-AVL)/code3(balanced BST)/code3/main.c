#include<stdio.h>
#include<stdlib.h>

int m=0;
int elements[10000];

/* A Binary Tree node */
struct node
{
    int key;
    struct node* left;
    struct node* right;
};

struct node* newNode(int key);
struct node* preorder_expression(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end)/2;

    struct node *root = newNode(arr[mid]);
    root->left =  preorder_expression(arr, start, mid-1);
    root->right = preorder_expression(arr, mid+1, end);
    return root;
}


struct node* newNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right= NULL;
    return node;
}



/* A utility function to print preorder traversal of BST */
void preOrder(struct node* node)
{
    if (node == NULL)
        return;

    elements[m]=node->key;
    m++;
    preOrder(node->left);
    preOrder(node->right);
}


/* Driver program to test above functions */
int main()
{

    int i,n;
    scanf("%d",&n);

    int arr[n];
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    /*int length;
    length = strlen(arr);*/

    n = sizeof(arr)/sizeof(arr[0]);
    struct node *root = preorder_expression(arr, 0, n-1);
    preOrder(root);

    for(i=0;i<n-1;i++)
        {
          printf("%d,",elements[i]);
        }
    printf("%d",elements[i]);

    return 0;
}
