#include <stdio.h>
#include <string.h>

/*
Write a routine  ungets(s) that will push back an entire string onto the input.
Should  ungets know about  buf and  bufp , or should it just use  ungetch ?
*/

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

void ungets(char s[]) {
    int len;

    len = strlen(s);
    while (i >= 0) {
        buf[i] = s[i];
        i--;
    }
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
