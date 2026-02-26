/**
 * @file linked_list.c
 * 
 * @brief Simple implementation of a linked list in C
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *p_next;
} Node;

typedef struct
{
    Node *head;
    int size;
} List;


void insert_node_front(Node *node, List *list)
{
    node->p_next = list->head;
    list->head = node;

    list->size++;
}

void insert_node_end(Node *node, List *list)
{
    Node *iterator = list->head;
    while (iterator->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = node;

    list->size++;
}

void remove_node_front(List *list)
{
    list->head = list->head->p_next;

    list->size--;
}

void remove_node_end(List *list)
{
    Node *iterator = list->head;
    if (list->size == 0)
    {
        return;
    }
    else if (list->size <= 1)
    {
        list->head = NULL;
        return;
    }
    // List has size 2 or larger
    while (iterator->p_next->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = NULL;

    list->size--;
}

void remove_node(Node *node, List *list)
{
    Node *iterator = list->head;
    while(iterator->p_next != NULL)
    {
        if (iterator->p_next == node)
        {
            iterator->p_next = node->p_next;
            return;
        }
        iterator = iterator->p_next;
    }
}

int main()
{

    return 0;
}