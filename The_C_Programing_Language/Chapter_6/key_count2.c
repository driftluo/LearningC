#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

char buf[1000];
int bufp = 0;

int getword(char *, int);
struct key * binsearch(char *, struct key *, int);

int main() {
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

// binsearch: find word in tab[0]...tab[n-1]
struct key *binsearch(char *word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

int getword(char *word, int lim) {
    int c, d, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {
        for ( ; --lim > 0; w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '"') {     // string
        for ( ; --lim > 0; w++) {
            if (*w == EOF) {
                break;
            } else if (*w == c) {
                w++;
                break;
            } else
             *w++ = getch();
        }
    } else if (c == '/') {      // comment
        if ((d = getch()) == '/')
            while ((d = getch()) != '\n')
                ;
        else if (d == '*') {
            while ((d = getch()) != EOF)
                if (d == '*')
                    if ((d = getch()) == '/')
                        break;
        }
    }
    *w = '\0';
    return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= 1000)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
