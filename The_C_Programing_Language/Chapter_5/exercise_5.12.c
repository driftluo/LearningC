#include <stdio.h>
#include <stdlib.h>

/*
Extend  entab and  detab to accept the shorthand
entab -m +n
to mean tab stops every  n columns, starting at column  m . Choose convenient (for the user)
default behavior.

把 settab 函数换为 esettab 函数，获取对应的参数进行设置
*/

#define MAXLINE 100
#define TABINC 8
#define YES 1
#define NO 0

void esettab(int argc, char *argv[], char *tab) {
    int i, inc, pos;

    if (argc <= 1) {
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    } else if (argc == 3 && *argv[1] == "-" && *argv[2] == '+') {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);
        for (i = 1; i <= MAXLINE; i++)
            if (i != pos)
                tab[i] = NO;
            else {
                tab[i] = YES;
                pos += inc;
            }
    } else {
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
