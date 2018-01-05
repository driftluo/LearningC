#include <stdio.h>
#include <string.h>

#define MAXLINE 1000  /* maximum input line length */

/*
Write the function  strindex(s,t) which returns the position of the  rightmost
occurrence of  t in  s , or  -1 if there is none.
*/

int getline(char line[], int max);
int strlindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; // pattern to search for

// find all lines matching pattern
int main() {
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if (strrindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

// getline: get line into s, return length
int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c = '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// strlindex: return index of t in s, -1 if none, from left to right
int strlindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

// strrindex: return index of t in s, -1 if none, from right to left
int strrindex(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s) -1; i >= 0; i--) {
        for (j=i, k=strlen(t)-1; k >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k >= 0)
            return i;
    }
    return -1;
}
