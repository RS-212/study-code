/**
 * @file dynamic_memory.c
 * 
 * @brief Excercise Program to learn dynamic memory allocation in C
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter an integer N...\n");

    // Allocate memory for N
    int *ptr_N = (int*)malloc(sizeof(int));
    if (!ptr_N)
    {
        printf("Error allocating memory for the int N. Exiting.\n");
        return -1;
    }
    
    // Store N at allocated memory address
    scanf("%d", ptr_N);

    // Allocate memory for n int variables
    int *ptr_ints = (int*)calloc(*ptr_N, sizeof(int));
    if (!ptr_ints)
    {
        printf("Error allocating memory for the N ints. Exiting.\n");
        return -1;
    }

    // Fill array with squares of their indicies
    for (int i = 0; i < *ptr_N; i++)
    {
        ptr_ints[i] = i * i;
    }

    // Resize array to twice it's size
    int *ptr_temp = realloc(ptr_ints, (*ptr_N) * 2);
    if (!ptr_temp)
    {
        printf("Error resizing array!. Exiting.\n");
        return -1;
    }
    ptr_ints = ptr_temp;

    // Fill remaining squares
    for (int i = *ptr_N; i < (*ptr_N) * 2; i++)
    {
        ptr_ints[i] = i * i;
    }

    // Print array
    printf("[ ");
    for (int i = 0; i < (*ptr_N) * 2; i++)
    {
        printf("%d", ptr_ints[i]);
        printf((i == ((*ptr_N) * 2 - 1)) ? " " : ", ");
    }
    printf("]\n");

    // Release memory
    free(ptr_N);
    free(ptr_ints);

    return 0;
}

// Differences between malloc() and calloc():
// malloc() allocates size bytes of memory and leaves it's content untouched
// calloc() allocates n blocks of size bytes of memory and initializes it to 0