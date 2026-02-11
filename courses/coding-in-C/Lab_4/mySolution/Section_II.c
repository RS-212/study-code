#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int get_string_length(char ca_input[])
{
    int length = 0;
    while (true)
    {
        if (ca_input[length] == '\0')
        {
            break;
        }
        length++;
    }
    return length;
}

/**
 * @brief checks if a given word is a palindrome
 * 
 * @param input string to check
 * @param length length of the string
 * 
 * @return returns 1 if input is a palindrome. returns 0 if input is not a palindrome.
 */
bool check_palindrome(char ca_input[])
{
    const int i_length = get_string_length(ca_input);
    const int i_middle = i_length / 2;     // rounds down in case of uneven numbers -> middle letter is ignored
    for (int i = 0; i < i_middle; i++)
    {
        printf("\n%c\n%c\n", ca_input[i], ca_input[i_length-i]);
        if (ca_input[i] != ca_input[i_length-i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char ca_user_input[101] = {0};

    printf("Please enter a word (max. 100 characters): ");
    fgets(ca_user_input, sizeof(ca_user_input), stdin);

    //printf("%s", ca_user_input);

    // Check for palindrome
    printf("Your provided word \"%s\" is ", ca_user_input);
    if (!check_palindrome(ca_user_input))
    {
        printf("not");
    }
    printf(" a palindrome.\n");

    return 0;
}