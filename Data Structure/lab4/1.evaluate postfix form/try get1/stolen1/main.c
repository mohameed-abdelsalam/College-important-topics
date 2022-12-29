#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
int data;
struct node* next;
};

struct node* top = NULL;

void push(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    int data;
    struct node* temp = top;
    if(top == NULL)
    {
          return 0;
    }
    data = top->data;
    top = top->next;
    free(temp);
    return data;
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

int operations(char x,int operand1,int operand2)
{
    if(x=='+')
        return operand1+operand2;
    else if(x=='-')
        return operand1-operand2;
    else if(x=='/'&&operand2!=0)
        return operand1/operand2;
    else if(x=='*')
        return operand1*operand2;

    else if(x=='%'&&operand2!=0)
        return operand1%operand2;
    else
    {
        return -1;
    }
}


int evaluate_postfix(char *arr,int len)
{
    int i,operand = 0;

    for(i=0;i<len;i++)
    {
        if(is_numeric_digit((arr[i])))
        {
            operand = (arr[i]-'0');
            push(operand);
        }
        else if(is_operator(arr[i]))
        {
            int result;
            int operand2 = pop();
            int operand1 = pop();

            result = operations((arr[i]),operand1,operand2);
            push(result);
        }
    }
   return pop();
}


int main()
{
    char arr[10000];
    int result,length;
    gets(arr);
    length = strlen(arr);
    int count1=0,count2=0;
    for(int i=0;i<length;i++)
    {
        if(is_numeric_digit(arr[i]))
            count1++;
        else if(is_operator(arr[i]))
            count2++;
    }
    if(count2<count1-1||count2>=count1)
    {
         printf("Not Valid");
         return 0;
    }


    result = evaluate_postfix(arr,length);
    if(result!=-1)
        printf("%d",result);
    else
        printf("Not Valid");
    return 0;
}
