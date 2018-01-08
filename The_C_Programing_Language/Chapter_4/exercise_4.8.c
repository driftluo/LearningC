#include <stdio.h>

/*
Suppose that there will never be more than one character of pushback. Modify
getch and  ungetch accordingly.
*/

char buf = 0;

/* getch */
int getch(void) {
    int c;

    if (buf != 0)
        c = buf;
    else
        c = getchar();
    buf = 0;
    return c;
}

void ungetch(int c) {
    if (buf != 0)
        printf("ungetch: too many character\n");
    else
        buf = c;
}
