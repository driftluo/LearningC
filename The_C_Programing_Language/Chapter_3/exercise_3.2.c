#include <stdio.h>
#define MAXLINE 1000
/*
Write a function  escape(s,t) that converts characters like newline and tab
into visible escape sequences like  \n and  \t as it copies the string  t to  s . Use a  switch . Write
a function for the other direction as well, converting escape sequences into the real characters.
*/

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

void main() {
    char s[MAXLINE] = "12\t345";
    char t[MAXLINE];

    escape(s, t);
    printf("%s\n", t);
    unescape(t, s);
    printf("%s\n", s);
}

void escape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            case '\\':
                t[j++] = '\\';
                t[j] = '\\';
                break;
            case '\a':
                t[j++] = '\\';
                t[j] = 'a';
                break;
            default:
                t[j] = s[i];
                break;
        }
        j++;
        i++;
    }
    t[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '\\':
                switch (s[++i]) {
                    case 'n':
                        t[j] = '\n';
                        break;
                    case 't':
                        t[j] = '\t';
                        break;
                    case 'a':
                        t[j] = '\a';
                        break;
                    case '\\':
                        t[j] = '\\';
                        break;
                }
                break;
            default:
                t[j] = s[i];
                break;
        }
        j++;
        i++;
    }
    t[j] = '\0';
}
