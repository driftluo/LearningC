#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

/*
Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.
*/

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void print(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
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
            case 'c':
                clear();
                break;
            case '?':
                print();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown commad %s\n", s);
                break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* clear: clear stack */
void clear(void) {
    sp = 0;
}

/* print: print the first element on stack */
void print(void) {
    int i;
    double tmp;

    if (sp > 1) {
        i = sp;
        tmp = val[--i];
        val[i] = val[--i];
        val[i] = tmp;
        printf("%.8g\n", tmp);
    } else if (sp > 0) {
        i = sp;
        printf("%.8g\n", val[--i]);
    }
    else
        printf("error: stack empty\n");
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i = 0, c, next;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;           /* not a number */

    if (c == '-') {
        next = getch();
        if (!isdigit(next) && next != '.')
            return c;       /* not a number */
        c = next;
        s[i] = '-';
    } else {
        c = getch();
    }
       
    while (isdigit(s[++i] = c))    /* collect integer part */
        c = getch();
    if (c == '.')   /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
