/**
 * @file files.c
 * 
 * @brief Test file management functions
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data.txt"
#define MAX_LINE_LENGTH 100



int main()
{
    // Open file to read and append and check for errors
    FILE *datei = fopen(FILENAME, "a+");
    if (datei == NULL)
    {
        // Error
        printf("Fehler beim Öffnen der Datei!");
        exit(1);
    }
    // -> If the file is not in the same directory: Error
    // -> Solution: add filepath


    // Read 1 character using fgetc()
    int zeichen = fgetc(datei);
    if(zeichen == EOF)
    {
        printf("Fehler beim Einlesen des Zeichens!\n");
    }
    else
    {
        printf("Eingelesenes Zeichen: %c\n", zeichen);     // The int zeichen is interpreted as a char
    }

    // Read 3 line using fgets()
    char zeile[MAX_LINE_LENGTH] = "";
    for (int i = 0; i < 3; i++)
    {
        if (fgets(zeile, MAX_LINE_LENGTH, datei) == NULL)
        {
            printf("Fehler beim Einlesen der Zeile!\n");
        }
        else
        {
            printf("Eingelesene Zeile: %s", zeile);     // No \n because the string from fgets() is newline-terminated
        }
    }

    // Read line 4 in a specific format using fscanf()
    char word1[MAX_LINE_LENGTH] = "";
    char word2[MAX_LINE_LENGTH] = "";
    int number = 0;
    char word3[MAX_LINE_LENGTH] = "";
    int success = fscanf(datei, "%s %s %d %s", &word1, &word2, &number, &word3);
    if (success == EOF)
    {
        printf("Fehler beim formatierten Lesen der Zeile!\n");
    }
    else
    {
        printf("Wort 1: %s, Wort 2: %s, Zahl: %d, Wort 3: %s\n", word1, word2, number, word3);
    }


    // Write character using fputc()
    for (int i = 0; i < 2; i++)
    {
        if (fputc('\n', datei) == EOF)      // Add newline to file
        {
            printf("Fehler beim Schreiben des Zeichens!\n");
        }
    }

    // Write 1 Line using fputs()
    if (fputs("This line is new!\n", datei) == EOF)
    {
        printf("Fehler beim schreiben der Zeile!\n");
    }

    // Write a formated string to the file
    if (fprintf(datei, "Float-Zahl: %f, String: %s\n", 12.0f, "Test String") < 0)
    {
        printf("Fehler beim formatierten Schreiben der Zeile!\n");
    }


    // Close file after use
    if (fclose(datei) == -1)
    {
        printf("Fehler beim schließen der Datei °o°");
    }

    return 0;
}