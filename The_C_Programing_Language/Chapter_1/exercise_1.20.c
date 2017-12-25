#include <stdio.h>

/*
Write a program  detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every  n columns.
Should  n be a variable or a symbolic parameter?

编写程序，将 tab 转换成对应数量的空格。
程序将 tab 转换为 4 个空格，如果有连续 tab ，不重复输出。
*/

void main() {
    int c, space;
    
    space = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            if (space == 0) {
                printf("    ");
                space = 1;
            }
        } else {
            putchar(c);
            space = 0;
        }
    }
}
