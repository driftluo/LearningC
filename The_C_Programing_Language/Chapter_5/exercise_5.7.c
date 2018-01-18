#include <stdio.h>
#include <string.h>

/*
Rewrite  readlines to store lines in an array supplied by  main , rather than
calling  alloc to maintain storage. How much faster is the program?

理论上会快一点，因为少了函数调用过程
*/

#define MAXLEN 1000
#define MAXSTOR 5000    // size of available storage space

// readlines: read input lines
int readlines(char *lineptr[], int maxlines, char *allocptr) {
    int len, nlines;
    char line[MAXLEN];
    char *p = allocptr;
    char *linestop = allocptr + MAXSTOR;

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len-1] = '\0';     // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}
