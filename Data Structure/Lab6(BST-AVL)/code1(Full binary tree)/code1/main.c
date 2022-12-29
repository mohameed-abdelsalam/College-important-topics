#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
}TreeNode;
 //struct Node *root = NULL;

 typedef struct tree{
    TreeNode *root;
    int size;
}Tree;


struct Node* newNode(int data)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}


//function to initialize tree
void createtree(Tree *pt){
    pt->root = NULL;
    pt->size = 0;

}

struct Node* create(int arr[], struct Node* root,int i, int n, Tree* pt)
{

   if(arr[i] == -1)
            {
              root = NULL;
            }

  else if (i < n)
    {
        struct Node* temp = newNode(arr[i]);
         root = temp;


        root->left = create(arr,root->left, 2 * i + 1, n, pt);


        root->right = create(arr,root->right, 2 * i + 2, n, pt);
    }

    return root;
}

bool isFullBinaryTree(struct Node *root) {
  // Checking tree emptiness
  if (root == NULL)
    return true;

  // Checking the presence of children
  if (root->left == NULL && root->right == NULL)
    return true;

  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  if ((root->data == -1) || (root->right == -1)||(root->left==-1))
      return true;

  return false;
}

int main() {
  int n,i;
  scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        {
          scanf("%d",&arr[i]);
        }

    Tree t;
    createtree(&t);
    struct Node* root = create(arr,root,0, n, &t);

    float num = log((n)+1) / log(2);

    if((int)num != num)
        printf("NO");
   else if (isFullBinaryTree(root))
    printf("YES\n");
  else
    printf("NO\n");
}

