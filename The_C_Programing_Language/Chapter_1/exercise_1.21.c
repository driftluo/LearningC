#include <stdio.h>
#define TABTOBLACK 4

/*
Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the  n -th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
将空格替换成 tab + 空格
*/

void main() {
    int c, space, count;
    int nblank, ntab;

    space = 0;
    count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (space == 0) {
                space = 1;
                count = 1;
            } else {
                ++count;
            }
        } else {
            if (count > 0) {
                ntab = count / TABTOBLACK;
                nblank = count % TABTOBLACK;
                for (; nblank > 0; --nblank) {
                    putchar(' ');
                }
                for (; ntab > 0; --ntab) {
                    putchar('\t');
                }
            }
            putchar(c);
            space = 0;
            count = 0;
        }
    }
}
