/*#include<stdio.h>
#include<stdlib.h>

 struct node
{
	int data;
	struct node *next;
}node;

node* RemoveDuplicates(node *head)
{
  node *p = head;
  node *q;
  while(p!=NULL && p->next!=NULL)
  {
      if(p->data == p->next->data)
      {
          q = p->next->next;

          if(q==NULL)
          {
              p->next = NULL;
              break;
          }

          p->next = q;
      }

      if(p->data != p->next->data)
        p = p->next;

  }

    return head;


}


int main()
{
	int a , i , n ;
	node *p,*q,*start;
	printf("Enter the number of nodes");
	scanf("%d",&n);

	printf("Enter all the nodes separated by space \n");
	p = (node*)malloc(sizeof(node));
	scanf("%d",&a);
	p->data = a;
	p->next = NULL;
	start = p;

	for(i=1;i<n;i++)
	 	{
		 	q = (node*)malloc(sizeof(node));
			scanf("%d",&a);
			q->data = a;
			q->next = NULL;
		 	p->next = q;
		 	p = p->next;

		}

start = RemoveDuplicates(start);

while(start!=NULL)
{
	printf("   %d", start->data);
	start = start->next;
}

}
*/
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node)
{
    while (node)
    {
        printf("%d \n", node->data);

        node = node->next;
    }
}
                       /******************************************************/

/void remove_duplicates(SinglyLinkedListNode* head)
{
          if (head==NULL)
            return;

    SinglyLinkedListNode* previous = head;
    SinglyLinkedListNode* current = head->next;

    while (current != NULL)
    {
        if (current->data == previous->data)
        {
            SinglyLinkedListNode* temp = current;
            current = current->next;
            previous->next = current;
            free(temp);
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    return head;
}

                     /**********************************************************/

/*int main()
{
    SinglyLinkedList* numbers = malloc(sizeof(SinglyLinkedList));
    numbers->head = NULL;
    numbers->tail = NULL;

    int numbers_count = parse_int(ltrim(rtrim(readline())));

    for (int i = 0; i < numbers_count; i++) {
        int numbers_item = parse_int(ltrim(rtrim(readline())));

        insert_node_into_singly_linked_list(&numbers, numbers_item);
    }

	remove_duplicates(numbers->head);
  	print_singly_linked_list(numbers->head);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
