#ifndef _DLL_
#define _DLL_

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
}LinkedListNode;

int add(LinkedListNode** head, int pos); // pos is position starting from head node(pos = 1)
int add_at_front(LinkedListNode** head);
int add_at_back(LinkedListNode** head);

#endif