#include <stdio.h>
#include <ctype.h>

/*
Write  getfloat , the floating-point analog of  getint . What type does
getfloat return as its function value?
*/

int getch(void);
void ungetch(int);
char buf = 0;

/* getfloat: get next float from input into *pn */
int getint(float *pn) {
    int c, sign, d, power=1;

    while (isspace(c = getch()))    // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * (*pn) + (c - '0');
    if (c == '.')
        c = getch();
    for (; isdigit(c); c = getch())
        *pn = 10.0 * (*pn) + (c - '0');
        power *= 10;
    *pn = sign * (*pn) / power;
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
