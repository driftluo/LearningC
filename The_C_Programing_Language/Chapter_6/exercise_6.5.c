#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Write a function  undef that will remove a name and definition from the table
maintained by  lookup and  install .
*/

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

char *strdup1(char *);

// hash: form hash value for string s
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

// lookup: look for s in hashtab
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)        // found
            return np;
    }
    return NULL;
}

// install: put (name, defn) in hashtab
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup1(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup1(defn)) == NULL)
        return NULL;
    return np;
}

char *strdup1(char *s) {
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

void undef(char *name) {
    struct nlist *np, *prev;
    unsigned hashval;

    prev = NULL;
    hashval = hash(name);
    for (np = hashtab[hashval]; np != NULL; np++) {
        if (strcmp(name, np->name) == 0)
            break;
        prev = np;
    }
    if (np != NULL) {
        if (prev == NULL)
            hashtab[hashval] = np->next;
        else
            prev->next = np->next;
        free(np->name);
        free(np->defn);
        free(np);
    }
}

int main() {
    struct nlist * p;

    install("name", "luoc");
    undef("name");
    if ((p = lookup("name")) == NULL) {
        printf("NONE");
    } else {
        printf("%s\n", p->defn);
    }
}
