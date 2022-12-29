#include <stdio.h>
#include <stdlib.h>


void reverseList()
{
    struct node *prevNode, *curNode;
    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; 	//Makes the first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; 		//Makes the last node as head
        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}


