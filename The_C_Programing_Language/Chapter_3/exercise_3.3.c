#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
Write a function  expand(s1,s2) that expands shorthand notations like  a-z in
the string  s1 into the equivalent complete list  abc...xyz in  s2 . Allow for letters of either
case and digits, and be prepared to handle cases like  a-b-c and  a-z0-9 and  -a-z . Arrange
that a leading or trailing  - is taken literally.
*/

int atoi(char s[]);
void expand(char s[], char t[]);

void main() {
    char s[] = "a-z, 1-4, A-M, A-";
    char t[100];
    int i = 0;
    

    while (s[i] != '\0') {
        
        expand(s, t);
        ++i;
    }
    printf("unexpended: %s\n", s);
    printf("expended  : %s\n", t);
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* shellshort: sort v[0]...v[n-1] into increasing order */
void shellshort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /=2) {
        for (i = gap; i < n; i++) {
            for (j = i-gap; j>=0 && v[j] > v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void expand(char s[], char t[]) {
    int i = 0;
    int j = 0;
    char p;

    while (s[i] != '\0') {
        switch (s[i]) {
            case '-':
                if (i == 0 || s[i+1] == '\0') {
                    t[j++] = '-';
                    ++i;
                    break;
                } else {
                    if ((s[i-1] >= 'A' && s[i-1] <= 'Z') && (s[i+1] >= 'A' && s[i+1] <= 'Z'))
                        ;
                    else if ((s[i-1] >= 'a' && s[i-1] <= 'z') && (s[i+1] >= 'a' && s[i+1] <= 'z'))
                        ;
                    else if ((s[i-1] >= '0' && s[i-1] <= '9') && (s[i+1] >= '0' && s[i+1] <= '9'))
                        ;
                    else {
                        /*
                            mismatched, like "1-x" or "3-M", error
                        */
                        printf("mismatched %c-%c\n", s[i-1], s[i+1]);
                        t[j++] = s[i-1];
                        t[j++] = s[i+1];
                        break;
                    }
                    p = s[i-1];
                    while (p != s[i+1]) {
                        t[j++] = p;
                        if (s[i+1] > s[i-1])
                            ++p;
                        else
                            --p;
                    }
                    t[j++] = p;
                    i += 2;
                }
                break;
            default:
                if (s[i+1] == '-' && s[i+2] != '\0')
                    i++;
                else {
                    t[j++] = s[i++];
                }
                break;
        }
    }
    t[j] = s[i];
}
