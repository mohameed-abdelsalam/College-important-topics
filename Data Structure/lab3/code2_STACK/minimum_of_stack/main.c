#include<stdio.h>
#include<stdlib.h>

int *main_stack , *supporting_stack;

void push(int element , int *top , int *stack)
{
  *top = *top + 1;
  stack[*top] = element;

}

int pop(int *stack , int *top)
{
  int element=0;
  if(*top > -1)
  {
  element = stack[*top];
  *top = *top - 1;
  }
  return element;
}


int main()
{

  int element =0, top_main=-1 , top_support=-1 ,supp_stack_pop_element=0, popped_element=0;
  int num_operations=0;
  main_stack=(int*)malloc(num_operations*sizeof(int));
  supporting_stack=(int*)malloc(num_operations*sizeof(int));
  scanf("%d",&num_operations);
  for(int i=0;i<num_operations;i++)
        {
            int  choice=0;
            scanf("%d",&choice);
            if(choice==1)
            {
                scanf("%d",&element);
                if(element<0)
                    break;
      push(element , &top_main , main_stack);


      if (top_support >= 0 && (element <= supporting_stack[top_support]))
      {
        push(element , &top_support , supporting_stack);
      }
      else if (top_support == -1)
      {
        push(element , &top_support , supporting_stack);
      }

            }
            else if(choice==2)
            {
              popped_element = pop(main_stack , &top_main);
              if (popped_element != -99999)
                  {
                    if (popped_element == supporting_stack[top_support])
                    {
                      supp_stack_pop_element = pop(supporting_stack , &top_support);
                    }
                  }
            }
            else if(choice ==3)
            {
                if (top_support > -1)
                 printf("%d \n", supporting_stack[top_support] );
                else
        printf("Empty\n");
            }

        }

  return 0;
}
