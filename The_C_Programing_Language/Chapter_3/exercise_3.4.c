#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
In a two's complement number representation, our version of  itoa does not
handle the largest negative number, that is, the value of  n equal to -(2 wordsize-1 ). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.

二进制补码中，int 的取值范围是 -2^31 ~ 2^31 - 1 即 -2147483648 ~ 2147483647
itoa 函数当 int n 为负数时，直接对这个数加负号，那么 -2147483648 加负号，并不能转成正数，会导致 itoa 函数出错
*/

void reverse(char s[]);
void itoa(int n, char s[]);

void main() {
    char s[1000];
    int a = -23411648;

    itoa(a, s);
    printf("%s\n", s);
}

// itoa: convert n to characters in s
void itoa(int n, char s[]) {
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
