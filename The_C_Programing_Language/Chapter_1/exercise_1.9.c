#include <stdio.h>

/*
Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
*/

void main() {
    int c, space;

    space = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (space == 0) {
                putchar(' ');
                space = 1;
            }
        }
        if (c != ' ') {
            space = 0;
            putchar(c);
        }
    }
}
