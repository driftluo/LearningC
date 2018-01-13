#include <string.h>

/*
Write a recursive version of the function  reverse(s) , which reverses the
string  s in place.
*/

void reverse(char s[]) {
    void reverser(char s[], int i, int len);

    return reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len) {
    int c, j;

    j = len - (i + 1);
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}
