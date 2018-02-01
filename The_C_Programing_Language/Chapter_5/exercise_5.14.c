#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Modify the sort program to handle a  -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that  -r works with  -n .

利用位运算：0 | 1 = 1， 0 | 2 = 2， 2 | 1 = 3，
        0 & 1 = 0， 0 & 2 = 0， 2 & 2 != 0.
第 0 位 =0 字符串排序
        =1 数字排序（-n）
第 1 位 =0 升序排序
        =1 降序排序（-r）
*/

#define NUMERIC 1   // numeric sort
#define DECR 2      // sort in decreasing order
#define LINES 100   // max lines

static char option = 0;

int readlines(char *lineptr[], int nlines);     // on sort_1.c
void writelines(char *lineptr[], int nlines, int decr);
void qsort_1(void *lineptr[], int left, int right, int (*comp)(void *, void *));       // on sort_1.c
int numcmp(char *, char *);     // on sort_1.c
int getline(char *, int);       // on sort_1.c
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
            default:
                printf("sort: illegel option %c\n", c);
                argc = 1;
                rc = -1;
                break;
        }
    }
    if (argc)
        printf("USage: sort -nr \n");
    else
        if ((nlines = readlines(lineptr, LINES)) > 0) {
            if (option & NUMERIC)
                qsort_1((void **) lineptr, 0, nlines-1, (int (*)(void*,void*)) numcmp);
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
