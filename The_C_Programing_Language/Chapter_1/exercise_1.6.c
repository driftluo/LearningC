#include <stdio.h>

/*
Verify that the expression  getchar() != EOF is 0 or 1.
*/

void main() {
    int c;

    c = (getchar() != EOF);
    printf("c == 0: %d,\tc==1: %d", c == 0, c == 1);
}
