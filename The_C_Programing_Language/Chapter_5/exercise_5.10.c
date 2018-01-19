#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/*
Write the program  expr , which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).
*/

#define MAX 100
#define NUMBER '0'

double val[1000];
int sp = 0;
char buf[1000];
int bufp = 0;

void ungets(char s[]);
int getop(char []);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    char s[MAX];
    double op2;

    while(--argc > 0) {
        ungets(*++argv);
        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown commad %s\n", s);
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

void ungets(char s[]) {
    strcpy(buf, s);
    bufp = strlen(s);
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : 0;
}

int getop(char s[]) {
    int c, i = 0;
    static int lastc = 0;

    if (lastc == 0)
        c = getch();
    else {
        c = lastc;
        lastc = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lastc = c;
    
    return NUMBER;
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void push(double f) {
    if (sp < 1000)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
