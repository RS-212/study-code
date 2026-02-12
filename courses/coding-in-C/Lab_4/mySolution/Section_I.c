/**
 * @file Section_I.c
 * @brief My solution to Section I
 * 
 */

#include <stdio.h>

/**
 * @brief change second letter to 'c'
 * 
 * @param[out] input_output string pointer to be changed
 */
void change_second_letter_to_c(char ca_input[])
{
    ca_input[1] = 'c'; 
    return;
}

int main()
{
    char ca_string[28] = "Curly bird catches the worm";
    char *ptr_ca_string = ca_string;
    
    char ca_string_to_edit[] = "AAtions speak louder than words";

    // Both variables contain an address -> no dereferencing needed!
    printf("%s\n", ca_string);
    //printf("%s\n", *ptr_ca_string); // Segmentation fault: *ptr_ca_string is the content = C -> printf tries to access address 'C'
    printf("%s\n", ptr_ca_string);

    *ptr_ca_string = 'E';
    *(ptr_ca_string+1) = 'a';   // Pointer arithmetic

    printf("%s\n", ca_string);

    //change_second_letter_to_c("AAtions speak louder than words");   // This causes a segmentation fault -> cannot edit literals!

    change_second_letter_to_c(ca_string_to_edit);

    printf("%s\n", ca_string_to_edit);

    return 0;
}