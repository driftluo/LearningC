#include <stdio.h>
#define MAXLINE 1000

/*
Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
*/

int getline(char line[], int maxline);

void main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len != 1 && line[0] != '\n') {
            printf("%s\n", line);
        }
    }
}

int getline(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == ' ' || c == '\t') {
            --i;
        } else {
            line[i] = c;
        }
    }
    if (c == '\n') {
        line[i] = '\n';
        line[++i] = '\0';
    }
    return i;
}
