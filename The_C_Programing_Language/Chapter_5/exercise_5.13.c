#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Write the program  tail , which prints the last  n lines of its input. By default,  n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last  n lines. The program should behave rationally no matter how unreasonable the
input or the value of  n . Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.
*/

#define DEFLINES 10 // default number of lines to print
#define LINES 100 // max of lines to print
#define MAXLEN 100 // max length of line

void error(char *);
int getline(char *, int limit);

int main(int argc, char *argv[]) {
    int n, last, nlines, len, first;
    char *lineptr[LINES];
    char line[MAXLEN];
    char *p;
    char *buf;
    char *bufend;

    if (argc <= 1)
        n = DEFLINES;
    else if (argc == 2 && (*++argv)[0] == '-') {
        n = atoi(argv[0] + 1);
        if (n >= LINES)
            n = LINES;
        else if (n < 1)
            n = DEFLINES;
    }
    else
        error("usage: tail [-n]");
    for (int i = 0; i < LINES; i++)
        lineptr[i] = NULL;
    if ((p = buf = malloc(MAXLEN * LINES)) == NULL)
        error("tail: cannot allocate buf");

    bufend = MAXLEN * LINES + buf;
    last = 0;       // index of last line read
    nlines = 0;     // number of lines read
    while ((len = getline(line, MAXLEN)) > 0) {
        if (p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;
        strcpy(lineptr[last], line);
        if (++last >= LINES)
            last = 0;
        p += len + 1;
        nlines++;
    }
    if (n > nlines)
        n = nlines;
    first = last - n;
    if (first < 0)
        first += LINES;
    for (int i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);
    return 0;
}

int getline(char *s, int lim) {
    int c;
    char *t = s;

    for (; --lim > 0 && (c = getchar()) != EOF && c != '\n';) {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return s - t;
}

void error(char *err) {
    printf("%s\n", err);
    exit(1);
}
