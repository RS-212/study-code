/**
 * @file linked_list.c
 * 
 * @brief Programm to unterstand how linked lists work in C -> Lab_7
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_NODES 50
#define INDEX_TO_REPLACE 3

// 1. Create Node Struct using typedef
typedef struct Node
{
    double value;
    struct Node *p_next;
} Node;

Node *create_node(double value);
void insert_node(Node *node, Node **head);
void free_list(Node **head);
void print_list(Node *head);
void print_array(int *arr, int len);

int main()
{
    srand(time(NULL)); // Set random seed so numbers are different every time the programm is run
    
    // 2. Define starting pointer 'head'
    Node *head = NULL;

    // 4. Append 50 new nodes to the list
    // In this case the new nodes are added to the FRONT of the list. Head remains a pointer to the first node
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

    // 5. Create int array with 51 elements
    int array[N_NODES+1];

    // 6. Fill array with 50 random numbers from index 0 to 49
    for(int i = 0; i < N_NODES; i++)
    {
        array[i] = rand() % 100; // I limit the numbers from 0 to 99 for easy of readability
    }

    // 7.
    // Create random number and insert it at index INDEX_TO_REPLACE of array
    int random_number = rand() % 100;
    // Shift all elements above INDEX_TO_REPLACE to the right
    for(int i = N_NODES; i > INDEX_TO_REPLACE; i--)
    {
        array[i] = array[i-1];
    }
    array[INDEX_TO_REPLACE] = random_number;

    // Create new node and insert it at index 3 of the linked list
    Node *new_node = create_node(42.0);
    if (!new_node)
    {
        printf("Error allocating memory for new Node!\n");
        free_list(&head);
        return 1;
    }
    // Iterate to index INDEX_TO_REPLACE-1 of the linked list and insert node after that
    Node *iterator = head;
    for(int i = 0; i < INDEX_TO_REPLACE-1; i++)
    {
        if(iterator == NULL)
        {
            printf("Error! Linked list is too short to insert new number!");
            break;
        }
        iterator = iterator->p_next;
    }
    new_node->p_next = iterator->p_next;
    iterator->p_next = new_node;

    // 8. Print array and list
    print_array(array, sizeof(array) / sizeof(array[0]));
    print_list(head);

    // 9.
    // Because we need to shift every element of the array to the right (47 shifts)
    // and just need to step through 3 elements of the linked list (3 steps)
    // adding the element to the linked list is way faster!
    // Additionally shifting elements in an array takes longer than stepping through pointers
    // so the linked list is faster because of this too.

    // 10. Free allocated memory
    free_list(&head);
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
    if(!new_node)
    {
        // Avoid writing to invalid memory if malloc fails
        return NULL;
    }
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
    node->p_next = *head;
    *head = node;
}

/**
 * @brief frees memory for an entire linked list
 * 
 * @param[out] head double pointer to the head of the linked list to free, head will point at NULL after this function finishes
 */
void free_list(Node **head)
{
    while ((*head) != NULL)
    {
        Node *next_node = (*head)->p_next;
        free(*head); // Free memory for head node -> head now points to free memory!
        *head = next_node; // head now points at the next node after head
        // Repeat until head points at NULL -> End of list
    }
}

/**
 * @brief prints a linked list
 * 
 * @param[in] head head to the list to be printed
 */
void print_list(Node *head)
{
    printf("[ ");
    if(head == NULL)
    {
        printf("]\n");
        return;
    }
    Node *iterator = head;
    while(iterator != NULL)
    {
        printf("%.2lf", iterator->value);
        iterator = iterator->p_next;
        if(iterator != NULL)
        {
            printf(",");
        }
        printf(" ");
    }
    printf("]\n");
}

/**
 * @brief prints contents of an int array
 * 
 * @param array pointer to the first element in the array
 * @param length length of the array
 */
void print_array(int *arr, int len)
{
    printf("[");
    for(int i = 0; i < len; i++)
    {
        printf(" %d", arr[i]);
        if(i < len-1)
        {
            printf(",");
        }
    }
    printf(" ]\n");
}