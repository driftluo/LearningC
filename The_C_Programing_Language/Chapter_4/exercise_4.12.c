#include <stdio.h>

/*
Adapt the ideas of  printd to write a recursive version of  itoa ; that is, convert
an integer into a string by calling a recursive routine.
*/

void itoa(int n, char s[]);
int i = 0;

void main() {
    char s[1000];
    int a = -2345;

    itoa(a, s);
    printf("%s\n", s);
}

void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

void itoa(int n, char s[]) {
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
