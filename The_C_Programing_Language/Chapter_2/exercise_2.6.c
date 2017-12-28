#include <stdio.h>

/*
 Write a function  setbits(x,p,n,y) that returns  x with the  n bits that begin at
position  p set to the rightmost  n bits of  y , leaving the other bits unchanged.
*/

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

void main() {
    unsigned i;
    i = setbits(12, 3, 1, 2);
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
