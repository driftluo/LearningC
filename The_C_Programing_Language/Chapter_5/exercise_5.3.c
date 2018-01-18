#include <stdio.h>

/*
Write a pointer version of the function  strcat that we showed in Chapter 2:
strcat(s,t) copies the string  t to the end of  s .
*/

// strcat: concatenate t to end of s; s must be big enough
void strcat1(char *s, char *t) {
    while(*s++ != '\0')
        ;
    s--;            // back to '\0'
    while(*s++ = *t++)
        ;
}

int main() {
    char s[100] = "123";
    char *t = "456";

    strcat1(s, t);
    printf("%s\t%s\n", s, t);
    return 0;
}
