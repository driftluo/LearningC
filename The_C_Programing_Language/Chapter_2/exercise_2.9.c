#include <stdio.h>

/*
In a two's complement number system,  x &= (x-1) deletes the rightmost 1-bit
in  x . Explain why. Use this observation to write a faster version of  bitcount .
*/

int bitcount(unsigned x);
int bitcount1(unsigned x);

void main() {
    unsigned x = 12;
    int i;

    i = bitcount(x);
    printf("%d\n", i);
    i = bitcount1(x);
    printf("%d\n", i);
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int bitcount1(unsigned x) {
    int b;
    
    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}
