#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
Write a version of  itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/

void reverse(char s[]);
void itoa(int n, char s[], int width);

void main() {
    char s[1000];
    int a = -23411648;

    itoa(a, s, 10);
    printf("%s\n", s);
}

// itoa: convert n to characters in s
void itoa(int n, char s[], int width) {
    int i, sign;
    
    if (n == INT_MIN) {
        i = 0;
        do {            /* generate digits in reverse order */
            s[i++] = -(n % 10) + '0';   /* get next digit */
        } while ((n /= 10) < 0);
        s[i++] = '-';
    } else {
        if ((sign = n) < 0) /* record sign */
            n = -n;     /* make n positive */
        i = 0;
        do {            /* generate digits in reverse order */
            s[i++] = n % 10 + '0';   /* get next digit */
        } while ((n /= 10) > 0);     /* delete it */
        if (sign < 0)
            s[i++] = '-';
    }
    while (i < width) {
        s[i++] = ' ';
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
