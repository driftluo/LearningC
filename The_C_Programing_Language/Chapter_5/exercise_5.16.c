#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Add the  -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with  -f
*/

#define NUMERIC 1   // numeric sort
#define DECR 2      // sort in decreasing order
#define FOLD 4      // fold upper and lower cases
#define DIR 8       // directory order
#define LINES 100   // max lines

static char option = 0;

int readlines(char *lineptr[], int nlines);     // on sort_1.c
void writelines(char *lineptr[], int nlines, int decr);
void qsort_1(void *lineptr[], int left, int right, int (*comp)(void *, void *));       // on sort_1.c
int numcmp(char *, char *);     // on sort_1.c
int getline(char *, int);       // on sort_1.c
int charcmp(char *, char *);
char *alloc(int);   // on alloc.c file

int main(int argc, char *argv[]) {
    char *lineptr[LINES];
    int nlines;
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        c = (*argv)[1];
        switch (c) {
            case 'n':
                option |= NUMERIC;
                break;
            case 'r':
                option |= DECR;
                break;
            case 'f':
                option |= FOLD;
                break;
            case 'd':
                option |= DIR;
                break;
            default:
                printf("sort: illegel option %c\n", c);
                argc = 1;
                rc = -1;
                break;
        }
    }
    if (argc)
        printf("USage: sort -nrfd \n");
    else
        if ((nlines = readlines(lineptr, LINES)) > 0) {
            if (option & NUMERIC)
                qsort_1((void **) lineptr, 0, nlines-1, (int (*)(void*,void*)) numcmp);
            else if (option & FOLD || option & DIR)
                qsort_1((void **) lineptr, 0, nlines-1, (int (*)(void*,void*)) charcmp);
            else
                qsort_1((void **) lineptr, 0, nlines-1, (int (*)(void*,void*)) strcmp);
            writelines(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort \n");
            rc = -1;
        }
    return rc;
}

void writelines(char *lineptr[], int nlines, int decr) {
    int i;

    if (decr) {
        for (i = nlines -1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    } else {
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}

int charcmp(char *s, char *t) {
    char a, b;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1: 0;

    do {
        if (dir) {
            while (!isalnum(*s) && *s != ' ' && *s != '\0')
                s++;
            while (!isalnum(*t) && *t != ' ' && *t != '\0')
                t++;
        }
        a = fold ? tolower(*s) : *s;
        b = fold ? tolower(*t) : *t;
        s++;
        t++;
        if (a == b && a == '\0')
            return 0;
    } while (a == b);
    return a - b;
}
