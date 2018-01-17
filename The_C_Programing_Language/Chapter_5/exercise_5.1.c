#include <stdio.h>
#include <ctype.h>

/*
As written,  getint treats a  + or  - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.
*/

int getch(void);
void ungetch(int);
char buf = 0;

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign, d;

    while (isspace(c = getch()))    // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     // it is not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        d = c;
        if (!isdigit(c = getch()))
            if (c != EOF)       // if not end, push back no-digit 
                ungetch(c);     
            ungetch(d);         // and then push back sign char
            return d;           // and then return sign char
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * (*pn) + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

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
