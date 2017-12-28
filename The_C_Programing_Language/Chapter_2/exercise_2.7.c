#include <stdio.h>

/*
Write a function  invert(x,p,n) that returns  x with the  n bits that begin at
position  p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

void main() {
    unsigned i;
    i = invert(12, 3, 2);
    printf("%u\n", i);
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned tmp1;
    unsigned tmp2;

    tmp1 = ((y & ~(~0 << n))) << (p+1-n);
    tmp2 = ~0 << (p+1) | ~(~0 << (p+1-n));

    return (x & tmp2) | tmp1;
}

unsigned invert(unsigned x, int p, int n) {
    unsigned tmp;

    tmp = ~(getbits(x, p, n));
    return setbits(x, p, n, tmp);
}
