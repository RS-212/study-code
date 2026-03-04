/**
 * @file stack.c
 * 
 * @brief Simple implementation of a stack in C
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
} Stack;

/**
 * @brief inserts a node at the front of the stack (as the new head)
 * 
 * @param[in] node node to be inserted
 * @param[out] stack stack to be modified
 */
void push(Node *node, Stack *stack)
{
    // No guards needed, this works even if head is NULL
    node->p_next = stack->head;
    stack->head = node;

    stack->size++;
}

/**
 * @brief removes the first node of the stack
 * 
 * @param[out] stack stack to be modified
 * 
 * @return Node pointer of the popped element, if Stack is empty: NULL
 */
Node* pop(Stack *stack)
{
    if(stack->head == NULL)
    {
        // No elements in stack -> nothing to remove
        return NULL;
    }
    Node *temp = stack->head;
    stack->head = stack->head->p_next;

    stack->size--;
    return temp;
}

/**
 * @brief prints a stack
 * 
 * @param[in] stack stack to be printed
 */
void print_stack(Stack *stack)
{
    printf("[ ");
    if(stack->head == NULL)
    {
        printf("]\n");
        return;
    }
    Node *iterator = stack->head;
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
    Stack *my_stack = malloc(sizeof(*my_stack));
    if(!my_stack)
    {
        printf("Error allocating memory!\n");
        return 1;
    }
    my_stack->head = NULL;
    my_stack->size = 0;

    Node *node1 = malloc(sizeof(*node1));
    if(!node1)
    {
        printf("Error allocating memory!\n");
        free(my_stack);
        return 1;
    }
    node1->p_next = NULL;
    node1->value = 12;

    Node *node2 = malloc(sizeof(*node2));
    if(!node2)
    {
        printf("Error allocating memory!\n");
        free(my_stack);
        free(node1);
        return 1;
    }
    node2->p_next = NULL;
    node2->value = 24;
    
    Node *node3 = malloc(sizeof(*node3));
    if(!node3)
    {
        printf("Error allocating memory!\n");
        free(my_stack);
        free(node1);
        free(node2);
        return 1;
    }
    node3->p_next = NULL;
    node3->value = 48;
    
    print_stack(my_stack);

    push(node1, my_stack);
    print_stack(my_stack);

    push(node2, my_stack);
    print_stack(my_stack);

    Node *temp = pop(my_stack);
    if(!temp)
    {
        printf("Error popping!\n");
        free(my_stack);
        free(node1);
        free(node2);
        free(node3);
        return 1;
    }
    print_stack(my_stack);
    
    push(node3,my_stack);
    print_stack(my_stack);

    // Free Memory
    free(my_stack);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}