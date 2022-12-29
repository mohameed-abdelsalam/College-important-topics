#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data ;
    struct node *left ,*right;
};

/*************  array implementation ***************/

//to enter no child make x=-1 ; so it will return NULL.
struct node*create()
{
    int exp;
    struct node *newnode; //to return the adress of the created node.
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&exp);
    newnode->data=exp;

    if (exp==-1)  //  if user enter -1 the next conditions will not be excuted .
    {
        return 0;
    }

       printf("enter left child of %d",x);
       newnode->left=create();
       printf("enter right childof %d",x);
       newnode->right=create();
       return newnode;
}


/**********************************************************************************/


//**********pre order( root -- left -- right ) **************

void preorder(struct node *root)
{
//this is the base condition (returninig condition it returns tp (root->left) again when it points to NUll and continue to the next line (root->right) )
    if(root==0)
        return;
    else
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}

//***************in order( left --root -- right ) *************

void inorder(struct node *root)
{

    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);

    }
}

//***************post order( left -- right-- root  ) ************

void postorder(struct node *root)
{
    if(root==0)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void main()
{
    struct node *root;
    printf("preorder is : ");
    preorder(root);
    inorder(root);
    postorder(root);
}
