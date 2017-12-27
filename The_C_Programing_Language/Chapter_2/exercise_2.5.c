#include <stdio.h>

/*
Write the function  any(s1,s2) , which returns the first location in a string  s1
where any character from the string  s2 occurs, or  -1 if  s1 contains no characters from  s2 .
(The standard library function  strpbrk does the same job but returns a pointer to the
location.)
*/

int any(char s[], char z[]);
int squeeze(char s[], int z);

void main() {
    char s[] = "abc";
    char z[] = "dfbz";

    printf("%d\n", any(s, z));
}

int any(char s[], char z[]) {
    int i = 0, j, n = -1;

    while (z[i] != '\0') {
        j = squeeze(s, z[i]);
        if (j < n && j != -1 || n == -1) {
            n = j;
        }
        i++;
    }
    return n;
}

int squeeze(char s[], int z) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == z) {
            return i;
        }
    }
    return -1;
}
