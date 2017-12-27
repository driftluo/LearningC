#include <stdio.h>

/*
Write a function  htoi(s) , which converts a string of hexadecimal digits
(including an optional  0x or  0X ) into its equivalent integer value. The allowable digits are  0
through  9 ,  a through  f , and  A through  F 
*/

int atoi(char s[]);
int htoi(char s[]);

void main() {
    char s[] = "0x667";
    int x;

    x = htoi(s);
    printf("%d", x);
}

/* atoi: convert s to integer */
int atoi(char s[]) {
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int htoi(char s[]) {
    int n = 0;
    int i = 2;
    int length = 0;

    if (s[0] != '0' && (s[1] != 'x' || s[1] != 'X')) {
        return -1;
    }

    while (s[length] != '\0') {
        ++length;
    }

    while (i < length) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - '0');
        }
        if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - 'a');
        }
        if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A');
        }
        ++i;
    }
    return n;
}
