#include <stdio.h>

/*
Write a program to count blanks, tabs, and newlines.
*/

void main() {
    int c, nspace;

    nspace = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++nspace;
        }
    }
    printf("%d\n", nspace);
}
