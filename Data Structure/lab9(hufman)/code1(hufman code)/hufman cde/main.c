#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 1000

typedef struct nodes {
   int data;
   int priority;
   struct nodes* next,*left,*right;
}node;
node *head=NULL; //referred to as NULL character

//*********************************************************

struct nodes* newNode(char data, unsigned freq)
{
    struct nodes* temp = (struct nodes*)malloc(sizeof(struct nodes));
    temp->left = NULL;
    temp->right = NULL;
    temp->next=NULL;
    temp->data = data;
    temp->priority = freq;
    return temp;
}
//***********************************************************
int only_one_element(struct nodes* queue)
{
    return (queue->next == NULL);
}

node* pop(node ** head_ptr){
   node* temp = *head_ptr;
    (*head_ptr) = (*head_ptr)->next;
    return temp;
}
//***********************************************************
struct nodes* buildHuffmanTree(char data[], int freq[],int size)
{
    struct nodes *left, *right, *top;
    for (int i = 0; i < size; ++i){
            if(i==0){
                head= newNode(data[i],freq[i]);
            }else{
        push(&head,newNode(data[i],freq[i]));
    }
}
    while (!only_one_element(head)){
        top = newNode('#',0);
        left = pop(&head);
        right = pop(&head);
        top->left = left;
        top->right = right;
        top->priority = top->left->priority + top->right->priority;
        if(head == NULL)
        head=top;
        else
        push(&head,top);
    }
    return pop(&head);
}

//*******************************************************
int  findFrequncy(char arr[],char newarr[],int freq[],int n)
{
    int m=0,count;
    int dublicate[n];
    for(int i=0;i<n;i++)
    {
        dublicate[i]=0;
        freq[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(dublicate[i])
            {
               continue;
            }
        count=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                dublicate[j]=1;
                count++;
            }
        }
        newarr[m]=arr[i];
        freq[m]=count;
        m++;
    }
    n=m;
    return n;
}
//********************************************************
struct nodes* temp2;
void HuffmanCodes(char data[], int freq[], int size)
{
    struct nodes* root = buildHuffmanTree(data, freq, size);
    temp2=root;
}

//******************************************************
void push(node **head_ptr,node*nodes){
    node*start =(*head_ptr);
   int freq= nodes->priority;
    if ((*head_ptr)->priority > freq) {
      nodes->next = *head_ptr;
      (*head_ptr) = nodes;
   } else {
      while (start->next != NULL && start->next->priority <= freq) {
    start = start->next;
      }
     nodes->next = start->next;
      start->next = nodes;
}
}
//********************************************************
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    printf("%d", arr[i]);
    printf("\n");
}
//*******************************************************
int leaf (node* root){
return (root->left==NULL && root->right==NULL);
}

int count(char arr[],char data[],int freq[]) {
    int array[128] = {0};
    int c = 0;
    int p=0;
    int temp=0;
    for (int i = 0; i<strlen(arr);i++) {
            if(array[arr[i]]==1){
            char *position_ptr = strchr(data,arr[i]);
            int position = position_ptr - data;
            freq[position]++;
                continue;
            }
        array[arr[i]] = 1;
        data[p]=arr[i];
        freq[p++]=1;
    }
    for (int i = 0; i<128; i++) {
        c += array[i];
    }
    return c;

}

//*****************************************************
void printelements (node* head){

while(head != NULL){
    printf("%c  %d\n",head->data, head->priority);
    head= head->next;
}
}
//***************************************************
void printCodes(struct nodes* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (leaf(root)) {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
//****************************************************
void huffmandecode(struct nodes* root , char arr[]){
 int len = strlen(arr);
 struct nodes *temporary = root;
 int n;
 for(int i = 0 ; i < len  ; i++){
     n=arr[i];
      if(arr[i] == '1')
           temporary=temporary->right;
      else
           temporary = temporary->left;
      if(temporary->data!='#'){
           printf("%c",temporary->data);
           temporary=root;
      }
 }
}
//******************************************************
int main()
{
   char arr[1000];
   gets(arr);
   int arr2;
   int n=strlen(arr);
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if(arr[i] < arr[j]) {
           arr2 = arr[i];
           arr[i] = arr[j];
           arr[j] = arr2;
      }
     }
    }
char data[n];
int freq[n];
int m = count(arr,data,freq);
HuffmanCodes(data,freq,m);
char root[1000];
gets(root);
huffmandecode(temp2,root);
    return 0;
}
