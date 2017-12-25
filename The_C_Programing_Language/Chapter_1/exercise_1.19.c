#include <stdio.h>
#define MAXLINE 1000
/*
Write a function  reverse(s) that reverses the character string  s . Use it to
write a program that reverses its input a line at a time.
*/

void reverse(char line[], int len);
int getline(char line[], int maxline);

void main() {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s\n", line);
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

void reverse(char line[], int len) {
    int i;
    char tmp;

    for (i = 0; i <= (len-2) / 2; ++i) {
        tmp = line[i];
        line[i] = line[len -i -2];
        line[len -i -2] = tmp;
    }
}
