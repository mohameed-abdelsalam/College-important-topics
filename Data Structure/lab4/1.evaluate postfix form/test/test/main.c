// C program to evaluate data of a postfix
// expression having multiple digit operands
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


struct node
{
   int data;
   struct node *next;
};
typedef struct node stack;


void push (stack **top, int element)
{
    stack *new;

    new = (stack *)malloc (sizeof(stack));
    if (new == NULL)
    {
       printf (“\n Stack is full”);
       exit(1);
    }

    new->data = element;
    new->next = *top;
    *top = new;
}


int pop (stack **top)
{
   int t;
   stack *p;

   if (*top == NULL)
   {
      printf (“\n Stack is empty”);
      exit(1);
   }
   else
   {
      t = (*top)->data;
      p = *top;
      *top = (*top)->next;
      free (p);
      return t;
   }
}



int isempty (stack *top)
{
   if (top == NULL)
        return (1);
    else
        return (0);
}
