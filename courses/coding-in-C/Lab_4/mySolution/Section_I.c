#include <stdio.h>

/**
 * @brief change second letter to 'c'
 * 
 * @param input_output string to be changed
 */
void change_second_letter_to_c(char ca_input[])
{
    ca_input[1] = 'c'; 
    return;
}

int main()
{
    char ca_string[28] = {"Curly bird catches the worm"};
    char *ptr_ca_string = ca_string;

    // Both variables contain the same address -> start address of ca_string
    printf("%p\n", ca_string);
    printf("%p\n", ptr_ca_string);

    // The following code is called pointer arithmetic
    *ptr_ca_string = 'E';
    *(ptr_ca_string+1) = 'a';

    printf("%s\n", ca_string);

    // This causes a segmentation fault -> cannot edit literals!
    //change_second_letter_to_c("AAtions speak louder than words");

    char ca_string_to_edit[] = "AAtions speak louder than words";
    change_second_letter_to_c(ca_string_to_edit);

    printf("%s\n", ca_string_to_edit);

    return 0;
}