#include <stdio.h>

/*
Write an alternative version of  squeeze(s1,s2) that deletes each character in
s1 that matches any character in the  string s2 
*/

void squeeze(char s[], int c);
void squeeze_str(char s[], char a[]);

void main() {
    char a[] = "123456";
    char b[] = "23";

    squeeze_str(a, b);
    printf("%s\n", a);
}

void squeeze_str(char s[], char a[]) {
    int i = 0;

    while (a[i] != '\0') {
        squeeze(s, a[i]);
        i++;
    }
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c)
            s[j++] = s[i];
    }
    s[j] = '\0';
}
