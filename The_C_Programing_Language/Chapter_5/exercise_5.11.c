#include <stdio.h>
#include <stdlib.h>

/*
Modify the program  entab and  detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.

这题题意没懂，以 tab 个字符为终结？
*/

#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);
void detab(char *tab);

int main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    settab(argc, argv, tab); // initialize tab stops
    entab(tab);              // replace blanks to tab
    return 0;
}

// set tab stop in array tab
void settab(int argc, char *argv[], char *tab)
{
    int i, pos;

    if (argc <= 1)
    { // default tab stops
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    }
    else
    { // user provided tab stops
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO;
        while (--argc > 0)
        {
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
}

// determine if pos is at a tab stop
int tabpos(int pos, char *tab)
{
    if (pos > MAXLINE)
        return YES;
    else
        return tab[pos];
}

// replace strings of blacks with tabs and blanks
void entab(char *tab)
{
    int c, pos;
    int nb = 0;
    int nt = 0;

    for (pos = 1; (c = getchar()) != EOF; pos++)
        if (c == ' ')
        {
            if (tabpos(pos, tab) == NO)
                ++nb;
            else
            {
                nb = 0;
                ++nt;
            }
        }
        else
        {
            for (; nt > 0; nt--)
            {
                putchar('\t');
                // putchar('t');
            }
            if (c == '\t')
                nb = 0;
            else
                for (; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (tabpos(pos, tab) != YES)
                    ++pos;
        }
}

void detab(char *tab) {
    int c, pos = 1;

    while((c == getchar()) != EOF) {
        if ( c == '\t') {
            do
                putchar(' ')
            while (tabpos(pos++, tab) != YES);
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
}
