#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

/**
 * @brief checks if a given word is a palindrome
 * 
 * @param input string to check
 * 
 * @return returns 1 if input is a palindrome. returns 0 if input is not a palindrome.
 */
bool check_palindrome(char ca_input[])
{
    int i_length = strlen(ca_input) - 1;    // -1 to ignore \0
    int i_middle = i_length / 2;        // rounds down in case of uneven numbers -> middle letter is ignored
    for (int i = 0; i < i_middle; i++)
    {
        //printf("\n%c\n%c\n", ca_input[i], ca_input[i_length-i]);
        char char1 = tolower(ca_input[i]);
        char char2 = tolower(ca_input[i_length-i]);
        if (char1 != char2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char ca_user_input[MAX_STR_LEN+2] = "";      // Read string can be max. 100 chars -> +2 for \0 and \n

    // Try to read in word. Retry if it fails
    while (true)
    {
        printf("Please enter a word (max. 100 characters): ");
        if (fgets(ca_user_input, sizeof(ca_user_input), stdin))
        {
            break;
        }
        printf("Failed to read word. Try again...\n");
    }

    // Remove \n from the end of the word
    char ca_edited_input[MAX_STR_LEN+1] = "";
    strncat(ca_edited_input, ca_user_input, strlen(ca_user_input)-1);

    if (check_palindrome(ca_edited_input))
    {
        printf("Your provided word \"%s\" is a palindrome.", ca_edited_input);
    }
    else
    {
        printf("Your provided word \"%s\" is not a palindrome.", ca_edited_input);
    }

    return 0;
}