#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct treenode{
    char data;
    struct treenode* left;
    struct treenode* right;
}node;
short unsigned int presence (char a ){
    switch (a)
    {
    case '+' :case '-' :
        return 1;
        break;
    case '*' :case '/' :case '%' :
        return 2;
        break;
    default:
        return -1;
    }
}
bool isoperator (char a){
    if (a=='+'||a=='-'||a=='*'||a=='/'||a=='%')
        return true;
    return false;
}
char* gotolast (char*ab){
    while(*ab!=')'){
        ab++;
        if (*ab=='(')
            ab = gotolast(ab);
        if (*ab=='\0')
            return ab;
    }
    return ++ab;
}
node* buildtree(char * first,char *last){
    char *ab=first,*leastprecence=first;
    if (first+1==last){
        node* current = (node *) malloc(sizeof(node));
        current->data=*first;
        current->left=NULL;
        current->right=NULL;
        return current;
    }
    if ((*first=='(' && *(last-1) == ')' && (gotolast(first)==last))){
        return buildtree (first+1,last-1);
    }
    while (ab!=last){
        if (*ab=='('){
            ab=gotolast(ab);
            continue;
        }
        if (isoperator(*ab) &&(presence(*ab)<=presence(*leastprecence)))
            leastprecence=ab ;
        ab++;
    }
    node* current = (node *) malloc(sizeof(node));
    current->data=*leastprecence;
    current->left=buildtree(first,leastprecence);
    current->right=buildtree(leastprecence+1,last);
    return current;
}
void postorder(node* a){
    if (a!=NULL){
        postorder(a->left);
        postorder(a->right);
        printf("%c",a->data);
    }
}
int main() {
    char str[100000];
    scanf("%s",str);
    char *ptrrr=str;
    node* aaa =buildtree(ptrrr,ptrrr+strlen(str));
    postorder (aaa);
    return 0;
}
