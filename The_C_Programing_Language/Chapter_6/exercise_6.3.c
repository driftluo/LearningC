#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
Write a cross-referencer that prints a list of all words in a document, and for
each word, a list of the line numbers on which it occurs. Remove noise words like ``the,''
``and,'' and so on.
*/

#define MAXWORD 100

struct linklist {       // linked list of line numbers
    int lnum;
    struct linklist *ptr;
};

struct tnode {
    char *word;
    struct linklist *lines;
    struct tnode *left;
    struct tnode *right;
};

char buf[1000];
int bufp = 0;

struct tnode *addtreex(struct tnode *, char *, int);
int getword(char *, int);
int noiseword(char *);
void treexprint(struct tnode *);
struct tnode * talloc(void);
struct linklist * lalloc(void);
void addln(struct tnode *, int);
char *strdup1(char *);

int main() {
    struct tnode *root;
    char word[MAXWORD];
    int linenum = 1;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && noiseword(word) == -1)
            root = addtreex(root, word, linenum);
        else if (word[0] == '\n')
            linenum++;
    }
    treexprint(root);
    return 0;
}

struct tnode *addtreex(struct tnode *p, char *w, int linenum) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup1(w);
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        addln(p, linenum);
    } else if (cond < 0)
        p->left = addtreex(p->left, w, linenum);
    else
        p->right = addtreex(p->right, w, linenum);
    return p;
}

void addln(struct tnode *p, int linenum) {
    struct linklist *temp;

    temp = p->lines;
    while (temp->ptr != NULL && temp->lnum != linenum)
        temp = temp->ptr;
    if (temp->lnum != linenum) {
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}

void treexprint(struct tnode *p) {
    struct linklist *temp;

    if (p != NULL) {
        treexprint(p->left);
        printf("%10s: ", p->word);
        for (temp = p->lines; temp != NULL; temp = temp->ptr)
            printf("%4d ", temp->lnum);
        printf("\n");
        treexprint(p->right);
    }
}

struct linklist *lalloc(void) {
    return (struct linklist *) malloc(sizeof(struct linklist));
}

int noiseword(char *w) {
    static char *nw[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "this",
        "to"
    };
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) - 1;

    while (low <= high) {
        mid = (low + high) /2;
        if ((cond = strcmp(w, nw[mid])) < 0)
            high = mid -1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
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

    while (isspace(c = getch()) && c != '\n')       // Do not skip the newline char
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
