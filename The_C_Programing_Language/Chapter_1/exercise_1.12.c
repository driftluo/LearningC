#include <stdio.h>

/*
Write a program that prints its input one word per line.
*/

#define IN 1
#define OUT 0

void main() {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (state == OUT) {
                putchar('\n');
                state = IN;
            }    
        } else {
            putchar(c);
            state = OUT;
        }
    }
}
