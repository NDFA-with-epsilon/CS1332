#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/* Not bothering with boilerplate of initialising a list. Structure of node is assumed to be minimalistic (see common.h) */

/* add node anywhere in the list */
int add(LinkedListNode** head, int pos)
{
    if(!head || !(*head) || !pos || pos < 0)
    {
        return -1;
    }

    if(pos == 1)
    {
        return add_at_front(head);
    }

    LinkedListNode* iter = *head;
    LinkedListNode* tmp = NULL;
    int cnt = 1;

    while(cnt < pos-1)
    {
        iter = iter->next;
        cnt++;
    }

    tmp = iter->next;
    
    iter->next = malloc(sizeof(*iter));
    iter->next->prev = iter;
    iter->next->next = tmp;
    tmp->prev = iter->next;

    iter = iter->next;
    iter->val = 0;

    return 0;
}

/* add at head position */

int add_at_front(LinkedListNode** head)
{
    if(!head || (!*head))
    {
        return -1;
    }

    LinkedListNode* new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->val = 0;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;

    return 0;
}

/* add at the end of list */

int add_at_back(LinkedListNode** head)
{
    if(!head || (!*head))
    {
        return -1;
    }

    LinkedListNode* iter = *head;
    while(iter->next != NULL)
    {
        iter = iter->next;
    }

    iter->next = malloc(sizeof(*iter));

    iter->val = 0;
    iter->next->next = NULL;
    iter->next->prev = iter;

    return 0;
}

int main(void)
{

    LinkedListNode* head = NULL;
    int pos = 4; //for self 
    int val = 5;

    if(insert_at(&head, pos, val) < 0)
    {
        printf("\n[-]   Couldn't insert a node in the specified list and position");
        return -1;
    }
}