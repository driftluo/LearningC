#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

// echo command-line arguments; 1st version
// int main(int argc, char *argv[]) {
//     int i;

//     for (i = 1; i < argc; i++) {
//         printf("%s%s", argv[i], (i < argc-1) ? " ": "");
//     }
//     printf("\n");
//     return 0;
// }

// echo command-line arguments; 2st version
// int main(int argc, char *argv[]) {
//     while (--argc > 0) {
//         printf("%s%s", *++argv, (argc > 1) ? " ": "");
//     }
//     printf("\n");
//     return 0;
// }

int getline(char *line, int max);

// find: print lines that match pattern from 1st arg
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (getline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
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
