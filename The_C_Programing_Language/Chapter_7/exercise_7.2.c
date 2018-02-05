#include <stdio.h>
#include <ctype.h>

/*
Write a program that will print arbitrary input in a sensible way. As a
minimum, it should print non-graphic characters in octal or hexadecimal according to local
custom, and break long text lines.
*/

#define MAXLINE 100
#define OCTLEN 6

int main() {
    int c, pos;
    int inc(int pos, int c);

    pos = 0;
    while ((c = getchar()) != EOF)
        if (iscntrl(c) || c == ' ') {
            pos = inc(pos, OCTLEN);
            printf(" \\%03o", c);
            if (c == '\n'){
                pos = 0;
                putchar('\n');
            }
        } else {
            pos = inc(pos, 1);
            putchar('\n');
        }
    return 0;
}

int inc(int pos, int n) {
    if (pos + n < MAXLINE)
        return pos * n;
    else {
        putchar('\n');
        return n;
    }
}
