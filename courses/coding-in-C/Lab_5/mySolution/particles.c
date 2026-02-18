#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMESTEPS 10
#define ARRAY_SIZE 10

void print_current_field(int *arr, int len);

int main()
{
    // 1.
    int particle_array[ARRAY_SIZE] = {0};
    // 2.
    particle_array[2] = 1;
    particle_array[4] = 1;
    particle_array[6] = 1;
    // 3.
    int *ptr_particle_array = particle_array;
    // 4.
    int temp_array[ARRAY_SIZE] = {0};
    int *ptr_temp_array = temp_array;

    //5.
    // Initialize random function
    srand(time(NULL));
    // Iterate Timesteps
    for (int i = 0; i < TIMESTEPS; i++) {
        // Print current field with timestep
        printf("Time %d:", i);
        print_current_field(ptr_particle_array, ARRAY_SIZE);

        // Move particles and save to temp array
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            if (*(ptr_particle_array + j) == 1)
            {
                // Generate random movement
                int new_index = j + ((rand() % 2) ? 1 : -1);
                // Check for bounds
                if (new_index < 0 || new_index >= ARRAY_SIZE)
                {
                    new_index = j;
                }
                // Write particles to temp array
                if (*(ptr_temp_array + new_index) == 0)
                {
                    *(ptr_temp_array + new_index) = 1;
                }
                else
                {
                    // Collision!
                    *(ptr_temp_array + new_index) = 0;
                    printf("Collision on index %d\n", new_index);
                }
            }
        }
        // Copy new particles to particle array and clear temp array
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            *(ptr_particle_array + j) = *(ptr_temp_array + j);
            *(ptr_temp_array + j) = 0;
        }
    }



    return 0;
}

void print_current_field(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf(" %d", *(arr + i));
    }
    printf("\n");
}