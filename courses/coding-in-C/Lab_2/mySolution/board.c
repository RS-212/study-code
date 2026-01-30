#include <stdio.h>

#define BOARD_SIZE 8

void printLine() {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE*4+1; i++) {
        printf((i%4) ? "-" : "+");
    }
    printf("\n");
}

void printLetters() {
    printf("    ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c  ", i+0x41);
    }
    printf("\n");
}

int main() {
    printLetters();
    printLine();
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d |", BOARD_SIZE-i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(((j+i)%2) ? "   " : "###");
            printf("|");
        }
        printf(" %d", BOARD_SIZE-i);
        printf("\n");
        printLine();
    }
    printLetters();
    return 0;
}