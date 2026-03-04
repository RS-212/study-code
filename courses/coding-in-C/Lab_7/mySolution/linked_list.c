/**
 * @file linked_list.c
 * 
 * @brief Programm to unterstand how linked lists work in C -> Lab_7
 */
#include <stdio.h>
#include <stdlib.h>

#define N_NODES 50

typedef struct Node
{
    double value;
    struct Node *p_next;
} Node;

Node *create_node(double value);
void insert_node(Node *node, Node **head);
void free_list(Node **head);

int main()
{
    Node *head = NULL;

    for(int i = 0; i < N_NODES; i++)
    {
        Node *temp_node = create_node(i);
        if(!temp_node)
        {
            printf("Error creating new node!\n");
            free_list(&head);
            return 1;
        }
        insert_node(temp_node, &head);
    }

    return 0;
}

/**
 * @brief creates a new node with a double value as content
 * 
 * @param[in] value double value of the node
 * 
 * @return Node * to the newly created node. returns NULL in case of error
 */
Node *create_node(double value)
{
    Node *new_node = malloc(sizeof *new_node);
    new_node->p_next = NULL;
    new_node->value = value;
    return new_node;
}

/**
 * @brief inserts a new node at the start of the list
 * 
 * @param[in] node new node to be inserted
 * @param[out] head head of the linked list
 */
void insert_node(Node *node, Node **head)
{
    node->p_next = head;
    *head = node;
}

/**
 * @brief frees memory for an entire linked list
 * 
 * @param[out] head head of the linked list to free, will become NULL
 */
void free_list(Node **head)
{
    
}