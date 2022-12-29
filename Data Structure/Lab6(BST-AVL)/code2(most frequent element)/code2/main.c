#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int item;
    struct tree *right, *left;
}TreeNode;


TreeNode* newNode(int value){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->item = value;
    node->left = node->right= NULL ;
    return node;
}

//recursive function to build tree from a sorted array
TreeNode* create(int arr[] , int first , int last , int *freq){

    if(first > last)
        return NULL;

    int mid = (first+last)/2;

    if(arr[mid] != -1)
        freq[arr[mid]-1]++;
    TreeNode* temp = newNode(arr[mid]);
    temp->left = create(arr , first , mid-1 , freq);
    temp->right = create(arr , mid+1 , last , freq);
    return temp;
}

int main(){
    TreeNode* root;
    int n;
    scanf("%d" , &n);

    int arr[n] , temp;
    for(int i = 0; i < n ; i++)
       {
        scanf("%d" , &arr[i]);
       }


    temp = arr[0];
    for(int i = 1; i < n ; i++)
        if(temp < arr[i])
         temp = arr[i];

//initialize freqent array by(zeros).
    int freq[temp];
    for(int i = 0 ; i < temp ; i++)
        freq[i] = 0;

    root = create(arr , 0 , n-1 , freq);

//get duplicated .
    int max = freq[0] , count = 0;
    for(int i = 1 ; i < temp ; i++)
        {
        if(freq[i] > 1)
            if(max < freq[i])
                max = freq[i];
        }

    for(int i = 0 ; i < temp ; i++)
        if(max == freq[i])
        {
           printf("%d\n" , i+1);
        }

    return 0;
}

