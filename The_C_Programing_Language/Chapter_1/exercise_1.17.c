#include <stdio.h>
#define MAXLINE 1000

/*
Write a program to print all input lines that are longer than 80 characters.
*/

int getline(char line[], int maxline);

void main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("%s\n", line);
        }
    }
}

int getline(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = '\n';
        line[++i] = '\0';
    }
    return i;
}
