#include <stdio.h>

/*
Write a program to print a histogram of the frequencies of different characters
in its input.
*/

void main() {
    int c, i, count, y;
    int ndigit[10];

    count = 0;
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        }
        ++count;
    }

    for (i = 0; i < 10; ++i) {
        y = ndigit[i];
        printf("%d: ", i);
        for (;ndigit[i] > 0; --ndigit[i]) {
            printf("#");
        }
        printf("\t%3.2f", y/(count * 1.0) * 100.0);
        printf("%%");
        printf("\n");
    }
}
