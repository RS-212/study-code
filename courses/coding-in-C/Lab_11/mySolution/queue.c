/**
 * @file queue.c
 * 
 * @brief Simple implementation of a queue in C
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
} Queue;

/**
 * @brief inserts a node at the front of the queue (as the new head)
 * 
 * @param[in] node node to be inserted
 * @param[out] queue queue to be modified
 */
void enqueue(Node *node, Queue *queue)
{
    // No guards needed, this works even if head is NULL
    node->p_next = queue->head;
    queue->head = node;

    queue->size++;
}

/**
 * @brief removes the last element of the queue
 * 
 * @param[out] queue queue to be modified
 * 
 * @return last Node of the queue, if empty: NULL
 */
Node *dequeue(Queue *queue)
{
    Node *iterator = queue->head;
    if (iterator == NULL)
    {
        // no elements in the queue
        return NULL;
    }
    else if (queue->size <= 1)
    {
        Node *temp = queue->head;
        queue->head = NULL;
        queue->size--;
        return temp;
    }
    // List has size 2 or larger
    while (iterator->p_next->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    Node *temp = iterator->p_next;
    iterator->p_next = NULL;

    queue->size--;
    return temp;
}

/**
 * @brief prints a queue
 * 
 * @param[in] queue queue to be printed
 */
void print_queue(Queue *queue)
{
    printf("[ ");
    if(queue->head == NULL)
    {
        printf("]\n");
        return;
    }
    Node *iterator = queue->head;
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
    Queue *my_queue = malloc(sizeof(*my_queue));
    my_queue->head = NULL;
    my_queue->size = 0;

    
    Node *node1 = malloc(sizeof(*node1));
    node1->p_next = NULL;
    node1->value = 12;

    Node *node2 = malloc(sizeof(*node2));
    node2->p_next = NULL;
    node2->value = 24;
    
    Node *node3 = malloc(sizeof(*node3));
    node3->p_next = NULL;
    node3->value = 48;

    print_queue(my_queue);

    enqueue(node1, my_queue);
    print_queue(my_queue);

    enqueue(node2, my_queue);
    print_queue(my_queue);

    dequeue(my_queue);
    print_queue(my_queue);

    enqueue(node3, my_queue);
    print_queue(my_queue);

    // Free Memory
    free(my_queue);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}