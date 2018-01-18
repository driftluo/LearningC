#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include  getline (Chapters 1 and 4),  atoi ,  itoa ,
and their variants (Chapters 2, 3, and 4),  reverse (Chapter 3), and  strindex and  getop
(Chapter 4).
*/

int getline(char *s, int lim) {
    int c;
    char *t = s;

    for (; --lim > 0 && (c = getchar()) != EOF && c != '\n';) {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return s - t;
}

void reverse(char *s) {
    char *t;

    for (t=s + (strlen(s)-1); s<t; s++,t--){
        char temp = *s;
        *s = *t;
        *t = temp;
    }
}

// string to int
int atoi(char *s) {
    int n, sign;

    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = n * 10 + (*s - '0');
    return n * sign;
}

// string to double
double atof(char *s) {
    double n, sign, power;

    for (; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1.0 : 1.0;
    if (*s == '-' || *s == '+')
        s++;
    for (n = 0.0; isdigit(*s); s++)
        n = n * 10.0 + (*s - '0');
    if (*s == '.')
        s++;
    for (power = 0.0; isdigit(*s); s++){
        n = n * 10.0 + (*s - '0');
        power *= 10.0;
    }
        
    return n * sign / power;
}

int main() {
    char s[100];
    int lim = 10;

    if (getline(s, lim) > 0)
        printf("%s\n", s);
}
