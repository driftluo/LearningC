#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Write a program that reads a C program and prints in alphabetical order each
group of variable names that are identical in the first 6 characters, but different somewhere
thereafter. Don't count words within strings and comments. Make 6 a parameter that can be
set from the command line.
*/

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

char buf[1000];
int bufp = 0;

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup1(char *);
int compare(char *, struct tnode *p, int, int *);

int main(int argc, char *argv[]) {
    struct tnode *root;
    char word[MAXWORD];
    int found = NO;     // YES if match was found
    int num;            // number of the first ident

    num = (--argc > 0 && (*++argv)[0] == '-') ? atof(argv[1]) : 6;
    root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtreex(root, word, num, &found);
        found = NO;
    }
    treeprint(root);
    return 0;
}

struct tnode *addtreex(struct tnode *p, char *w, int num, int *found) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    } else if ((cond = compare(w, p, num, found)) < 0) {
        p->left = addtreex(p->left, w, num, found);
    } else if (cond > 0) {
        p->right = addtreex(p->left, w, num, found);
    }
    return p;
}

// compare: compare words and unpdate p->match
int compare(char *s, struct tnode *p, int num, int *found) {
    int i;
    char *t = p->word;

    for (i = 0; *s == *t; i++, s++, t++) {
        if (*s == '\0')
            return 0;
    }
    if (i >= num) {
        *found = YES;
        p->match = YES;
    }
    return *s - *t;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        if (p->match) {
            printf("%s\n", p->word);
        }
        treeprint(p->right);
    }
}

// talloc: make a tnode
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// make a duplicate of s
char *strdup1(char *s) {
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
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
