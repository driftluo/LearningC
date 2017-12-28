#include <stdio.h>

/*
Rewrite the function  lower , which converts upper case letters to lower case,
with a conditional expression instead of  if-else 
*/

int lower(int c);

void main() {
    int c;

    c = lower('N');
    printf("%d\t%d\n", 'n', c);
}

int lower(int c) {
    return c >= 'A' && c <= 'Z' ? 'a' + c - 'A' : c;
}

int higher(int c) {
    return c >= 'a' && c <= 'z' ?  'A' + c - 'a'  : c;
}
