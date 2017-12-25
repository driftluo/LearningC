#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];

int getline(char line[], int maxline);

void main() {
    char line[MAXLINE];
    int len = 0;
    int t = 0;
    int brace = 0, bracket = 0, parenthesis = 0;
    int s_quote = 1, d_quote = 1;

    while ((len = getline(line, MAXLINE)) > 0) {
        t = 0;
        while (t < len) {
            if (line[t] == '{') {
                bracket++;
            }
            if (line[t] == '}') {
                bracket--;
            }
            if (line[t] == '[') {
                brace++;
            }
            if (line[t] == ']') {
                brace--;
            }
            if (line[t] == '(') {
                parenthesis++;
            }
            if (line[t] == ')') {
                parenthesis--;
            }
            if (line[t] == '\'') {
                s_quote *= -1;
            }
            if (line[t] == '"') {
                d_quote *= -1;
            }
            t++;
        }
    }
    if (brace != 0) {
        printf("Missing brace");
    }
    if (bracket != 0) {
        printf("Missing bracket");
    }
    if (parenthesis != 0) {
        printf("Missing parenthesis");
    }
    if (s_quote != 1) {
        printf("Missing single quete");
    }
    if (d_quote != 1) {
        printf("Missing double quete");
    }
    if (brace == 0 && bracket == 0 && parenthesis == 0 && s_quote == 1 && d_quote == 1) {
        printf("Ok");
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
