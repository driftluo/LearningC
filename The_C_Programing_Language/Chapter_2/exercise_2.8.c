#include <stdio.h>

/*
Write a function  rightrot(x,n) that returns the value of the integer  x rotated
to the right by  n positions.
*/

unsigned rightrot(unsigned x, int n);

void main() {
    unsigned i;

    i = rightrot(1, 1);
    printf("%u\n", i);
}

unsigned rightrot(unsigned x, int n) {
    unsigned int zero = 0;

    while (n > 0) {
        if ((x & 1) == 1) {
            x = (x >> 1) | (~(~zero >> 1));
        } else {
            x = x >> 1;
        }
        --n;
    }
    return x;
}
