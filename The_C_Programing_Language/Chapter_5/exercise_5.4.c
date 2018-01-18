#include <stdio.h>

/*
Write the function  strend(s,t) , which returns 1 if the string  t occurs at the
end of the string  s , and zero otherwise.
*/

// strend: if t occurs at the end of s, return 1, else return 0
int strend(char *s, char *t) {
    int i=0, j=0;

    while(*s++ != '\0')
        i++;
    while(*t++ != '\0')
        j++;
    if (i<j)
        return 0;
    else
        s = s+i-j;
        while((*s++ == *t++) && *s != '\0')
            ;
        if (*s == '\0')
            return 1;
        else
            return 0;
}

int main() {
    char *s = "12345";
    char *t = "345";
    int i;

    i = strend(s, t);
    printf("%d\n", i);
    return 0;
}
