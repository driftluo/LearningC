#include <stdio.h>

/*
Our  getch and  ungetch do not handle a pushed-back  EOF correctly. Decide
what their properties ought to be if an  EOF is pushed back, then implement your design.

char 的取值范围比 int 小，0xff 转成 整数 的时候，根据机器不同，可能转成 0xffff 或者 0x00ff，即 -1 或者 255
*/

#define MAX 100

int bufp = 0;
int buf[MAX];

/* get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
