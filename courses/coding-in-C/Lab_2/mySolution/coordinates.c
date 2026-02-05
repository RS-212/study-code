#include <stdio.h>

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c%d ", j+'A', 8-i);
        }
        printf("\n");
    }
    return 0;
}