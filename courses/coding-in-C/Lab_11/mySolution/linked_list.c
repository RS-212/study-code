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

/**
 * @brief inserts a node at the front of the linked list (as the new head)
 * 
 * @param[in] node node to be inserted
 * @param[out] list list to be modified
 */
void insert_node_front(Node *node, List *list)
{
    // No guards needed, this works even if head is NULL
    node->p_next = list->head;
    list->head = node;

    list->size++;
}

/**
 * @brief inserts a node at the end of the linked list
 * 
 * @param[in] node node to be inserted
 * @param[out] list list to be modified
 */
void insert_node_end(Node *node, List *list)
{
    Node *iterator = list->head;
    if(iterator == NULL)
    {
        // No elements in list -> set head to node
        list->head = node;
        list->size++;
        return;
    }
    while (iterator->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = node;

    list->size++;
}

/**
 * @brief inserts a node at the given index in the linked list
 * 
 * @param[in] node node to be inserted
 * @param[out] list list to be modified
 * @param[in] index intended index of the list
 * 
 * @return 1 on success, 0 on fail (out of range)
 */
int insert_node_at(Node *node, List *list, int index)
{
    if(index == 0)
    {
        insert_node_front(node, list);
        return 1;
    }
    if(index >= list->size)
    {
        // Out of range!
        return 0;
    }
    Node *iterator = list->head;
    for(int i = 0; i < index-1; i++)
    {
        if(iterator->p_next == NULL) // Should never trigger, due to above size check
        {
            return 0;
        }

        iterator = iterator->p_next;
    }
    node->p_next = iterator->p_next;
    iterator->p_next = node;

    list->size++;
    return 1;
}

/**
 * @brief removes the first node of the list
 * 
 * @param[out] list list to be modified
 * 
 * @return 1 on success, 0 on fail (no elements in list)
 */
int remove_node_front(List *list)
{
    if(list->head == NULL)
    {
        // No elements in list -> nothing to remove
        return 0;
    }
    list->head = list->head->p_next;

    list->size--;
    return 1;
}

/**
 * @brief removes the last node of the list
 * 
 * @param[out] list list to be modified
 * 
 * @return 1 on success, 0 on fail (no elements in list)
 */
int remove_node_end(List *list)
{
    Node *iterator = list->head;
    if (iterator == NULL)
    {
        // no elements in the list
        return 0;
    }
    else if (list->size <= 1)
    {
        list->head = NULL;
        list->size--;
        return 1;
    }
    // List has size 2 or larger
    while (iterator->p_next->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = NULL;

    list->size--;
    return 1;
}

/**
 * @brief removes a specific node from the list
 * 
 * @param[in] node note to be removed
 * @param[out] list list to be modified
 * 
 * @return 1 on success, 0 on fail (no elements in list)
 */
int remove_node(Node *node, List *list)
{
    Node *iterator = list->head;
    if(iterator == NULL)
    {
        // No elements in list
        return 0;
    }
    while(iterator->p_next != NULL)
    {
        if (iterator->p_next == node)
        {
            iterator->p_next = node->p_next;
            return 1;
        }
        iterator = iterator->p_next;
    }
    return 0;
}

/**
 * @brief removes a node at the given index in the linked list
 * 
 * @param[out] list list to be modified
 * @param[in] index intended index of the list
 * 
 * @return 1 on success, 0 on fail (out of range)
 */
int remove_node_at(List *list, int index)
{
    if(list->head == NULL)
    {
        // No Element in list
        return 0;
    }
    if(index == 0)
    {
        return remove_node_front(list);
    }
    if(index >= list->size)
    {
        // Out of range!
        return 0;
    }
    Node *iterator = list->head;
    for(int i = 0; i < index-1; i++)
    {
        if(iterator->p_next == NULL) // Should never trigger, due to above size check
        {
            return 0;
        }

        iterator = iterator->p_next;
    }
    // If operating at the end of the list avoid reading out of scope
    if((index+1) == list->size)
    {
        iterator->p_next = NULL;
    }
    else
    {
        iterator->p_next = iterator->p_next->p_next;
    }

    list->size--;
    return 1;
}

/**
 * @brief prints a linked list
 * 
 * @param[in] list list to be printed
 */
void print_list(List *list)
{
    printf("[ ");
    if(list->head == NULL)
    {
        printf("]\n");
        return;
    }
    Node *iterator = list->head;
    while(iterator != NULL)
    {
        printf("%d", iterator->value);
        iterator = iterator->p_next;
        if(iterator != NULL)
        {
            printf(",");
        }
        printf(" ");
    }
    printf("]\n");
}

int main()
{
    // Create some nodes
    Node *node1 = malloc(sizeof(*node1));
    if(!node1)
    {
        printf("Error allocating memory!\n");
        return 1;
    }
    node1->value = 13;
    node1->p_next = NULL;

    Node *node2 = malloc(sizeof(*node2));
    if(!node2)
    {
        printf("Error allocating memory!\n");
        free(node1);
        return 1;
    }
    node2->value = 42;
    node2->p_next = NULL;

    Node *node3 = malloc(sizeof(*node3));
    if(!node3)
    {
        printf("Error allocating memory!\n");
        free(node1);
        free(node2);
        return 1;
    }
    node3->value = 55;
    node3->p_next = NULL;

    Node *node4 = malloc(sizeof(*node4));
    if(!node4)
    {
        printf("Error allocating memory!\n");
        free(node1);
        free(node2);
        free(node3);
        return 1;
    }
    node4->value = 17;
    node4->p_next = NULL;

    List *my_list = malloc(sizeof(*my_list));
    if(!my_list)
    {
        printf("Error allocating memory!\n");
        free(node1);
        free(node2);
        free(node3);
        free(node4);
        return 1;
    }
    my_list->head = node1;
    my_list->size = 1; // 1 because it already contains a head node

    print_list(my_list);

    // Append node2 to List
    insert_node_end(node2, my_list);
    print_list(my_list);

    // Insert node3 at the front
    insert_node_front(node3, my_list);
    print_list(my_list);

    // Insert node4 at index 1
    insert_node_at(node4, my_list, 1);
    print_list(my_list);

    // Remove node at index 2
    remove_node_at(my_list, 2);
    print_list(my_list);

    // Free memory for list and nodes
    free(my_list);
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}