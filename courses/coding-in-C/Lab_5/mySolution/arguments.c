#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (!(argc > 1))
    {
        printf("This program expects at least one(1) argument!\nExiting...\n");
        return -1;
    }
    
    for (int i = 0; i < argc; i++)
    {
        char *argument = argv[i];
        //char *argument = *(argv + i);
        
        printf("Argument %d at address \"%p\" has content: %s (length: %d)\n", i, argument, argument, (int)strlen(argument));
    }

    /*
    5. arr[i] == *(arr + i) -> Because arrays contain the address of their first element, they can be handled like pointers
    6. Arrays are pointers to their first element, with additional information about length (sizeof(arr)).
    */

    return 0;
}