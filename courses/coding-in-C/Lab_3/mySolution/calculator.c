#include <stdio.h>

int main() {
    float f_num1 = 0;
    float f_num2 = 0;
    char c_operator = ' ';
    float f_result = 0;

    do
    {
        printf("Input the first floating point number...\n\n");
    } while (!scanf("%f", &f_num1));
    do
    {
        printf("\nInput the second floating point number...\n\n");
    } while (!scanf("%f", &f_num2));

    while (1)
    {
        printf("\nWhich operation? add(+), subtract(-), multiply(*), divide(/)\n\n");
        scanf(" %c", &c_operator);

        // Check division by zero
        if (c_operator == '/' && f_num2 == 0)
        {
            printf("\nYou cannot divide by zero! Try again...\n");
            continue;
        }
        // Check validity of operator
        if (c_operator == '+' || c_operator == '-' || c_operator == '*' || c_operator == '/')
        {
            break;
        }
        printf("\nInvalid operation! Try again...\n\n");
    }

    /* Execute calculation
    if (c_operator == '+')
    {
        f_result = f_num1 + f_num2;
    } else if (c_operator == '-')
    {
        f_result = f_num1 - f_num2;
    } else if (c_operator == '*')
    {
        f_result = f_num1 * f_num2;
    } else if (c_operator == '/')
    {
        f_result = f_num1 / f_num2;
    }
    */

    switch (c_operator) {
        case '+':
            f_result = f_num1 + f_num2;
            break;
        case '-':
            f_result = f_num1 - f_num2;
            break;
        case '*':
            f_result = f_num1 * f_num2;
            break;
        case '/':
            f_result = f_num1 / f_num2;
            break;
    }

    // Print result
    printf("\n%f %c %f = %f\n", f_num1, c_operator, f_num2, f_result);

    return 0;
}