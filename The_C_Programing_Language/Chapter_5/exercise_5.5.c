#include <stdio.h>

/*
 Write versions of the library functions  strncpy ,  strncat , and  strncmp , which
operate on at most the first  n characters of their argument strings. For example,
strncpy(s,t,n) copies at most  n characters of  t to  s . Full descriptions are in Appendix B.
*/

// strncpy: copy at most the first n character of t to s
void strncpy1(char *s, char *t, int n) {
    int i = 1;

    if (n <= 0)
        return;
    while ((*s++ = *t++) && i < n)
        i++;
}

// strncmp: return <0 if s<t, 0 if s==t, >0 if s>t, pointer version
int strncmp1(char *s, char *t, int n) {
    for (int i = 1; *s==*t && i < n; s++, t++, i++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

// strncat: concatenate t to end of s; s must be big enough
void strncat1(char *s, char *t, int n) {
    int i = 1;

    if (n <= 0)
        return;
    while(*s++ != '\0')
        ;
    s--;            // back to '\0'
    while((*s++ = *t++) && i < n)
        i++;
    if (*(s+i) != '\0')
        *(s+i+1) = '\0';
}

int main() {
    char s[100] = "12345";
    char *t = "13";
    int i;

    strncpy1(s, t, 0);
    printf("%s\n", s);
    i = strncmp1(s, t, 1);
    printf("%d\n", i);
    strncat1(s, t, 0);
    printf("%s\n", s);
    return 0;
}
