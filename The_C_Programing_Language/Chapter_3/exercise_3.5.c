#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
Write the function  itob(n,s,b) that converts the integer  n into a base  b
character representation in the string  s . In particular,  itob(n,s,16) formats  s as a
hexadecimal integer in  s .
*/

void reverse(char s[]);
void itoa(int n, char s[], int b);

void main() {
    char s[1000];
    int a = -2147483648;

    itoa(a, s, 16);
    printf("%s\n", s);
}

// itoa: convert n to characters in s
void itoa(int n, char s[], int b) {
    int i, sign;
    char hex[] = "0123456789ABCDEF";

    if (n == INT_MIN) {
        i = 0;
        do {            /* generate digits in reverse order */
            s[i++] = hex[-(n % b)];   /* get next digit */
        } while ((n /= b) < 0);
        s[i++] = '-';
    } else {
        if ((sign = n) < 0) /* record sign */
            n = -n;     /* make n positive */
        i = 0;
        do {            /* generate digits in reverse order */
            s[i++] = hex[n % b];   /* get next digit */
        } while ((n /= b) > 0);     /* delete it */
        if (sign < 0)
            s[i++] = '-';
    }

    s[i] = '\n';
    reverse(s);
}

void reverse(char s[]) {
    int i=0;

    for (int j=strlen(s)-1; i<j; i++,j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
