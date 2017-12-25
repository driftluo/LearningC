#include <stdio.h>

/*
Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the  n -th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
将输入的长字符串改成 n 行短的，以 . 为分割符
*/

void main() {
    int c, space;
    
    space = 0;
    while ((c = getchar()) != EOF) {
        if (c == '.') {
            if (space == 0) {
                printf("\n");
                space = 1;
            }
        } else {
            putchar(c);
            space = 0;
        }
    }
}
