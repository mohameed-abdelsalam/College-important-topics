#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>


struct node
{
    int data ;
    struct node *left ,*right;

};

//print postfix expression .
void postorder(struct node *root)
{
//this is the base condition (returninig condition) it returns to (root->left) again when it points to NUll and continue to the next line (root->right) )
    if(root==0)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

bool is_operator(char x)
{
    if(x=='+'||x=='-'||x=='/'||x=='*'||x=='%')
        return true;
    else
        return false;
}

int is_numeric_digit(char x)
{
    if(x>='0'&&x<='9')
        return 1;
    else
        return 0;
}
////////////////////////////////////////////////////////////////////////


/*************  TREE implementation ***************/

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

       newnode->left=create();
       newnode->right=create();
       return 0;
}

/////////////////////////////////////////////////////////////////////////

char stack[10000];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    scanf("%s",exp);
    e = exp;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            printf("%c",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c",pop());
    }

    struct node *root;
    root=0;
    root=create();
    postorder(root);
    return 0;
}
