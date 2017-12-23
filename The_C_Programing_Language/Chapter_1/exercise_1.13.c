#include <stdio.h>

/*
Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#define IN 1
#define OUT 0

void main() {
    int c, state, length;

    state = OUT;
    length = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == OUT) {
                printf(": ");
                for (; length > 0; length--) {
                    putchar('#');
                }
                putchar('\n');
                state = IN;
            }    
        } else {
            putchar(c);
            state = OUT;
            ++length;
        }
    }
}
