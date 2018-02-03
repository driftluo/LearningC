#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
Write a program that prints the distinct words in its input sorted into decreasing
order of frequency of occurrence. Precede each word by its count.
*/

#define MAXWORD 100
#define NDISTINCT 1000

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);
struct tnode *talloc(void);
char *strdup1(char *);
void treeprint(struct tnode *);

char buf[1000];
int bufp = 0;
struct tnode *list[NDISTINCT];
int ntn = 0;

int main() {
    struct tnode *root;
    char word[MAXWORD];
    int i;

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treestore(root);
    sortlist();
    for (i = 0; i < ntn; i++)
        printf("%2d:%20s\n", list[i]->count, list[i]->word);
    // treeprint(root);
    return 0;
}

void treestore(struct tnode *p) {
    if (p != NULL) {
        treestore(p->left);
        if (ntn < NDISTINCT)
            list[ntn++] = p;
        treestore(p->right);
    }
}

void sortlist(void) {
    int gap, i, j;
    struct tnode *temp;

    for (gap = ntn/2; gap > 0; gap /= 2)
        for(i = gap; i < ntn; i++)
            for (j = i-gap; j >= 0; j -= gap) {
                if ((list[j]->count) >= (list[j+gap]->count))
                    break;
                temp = list[j];
                list[j] = list[j+gap];
                list[j+gap] = temp;
            }
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup1(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
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

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
