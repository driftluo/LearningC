#include <stdio.h>

/*
Define a macro  swap(t,x,y) that interchanges two arguments of type  t .
(Block structure will help.)
*/

#define swap(t, x, y) { t temp; temp = x; x = y; y = temp; }

int main() {
    int x, y;

    x = 5;
    y = 15;

    swap(int, x, y);
    printf("%d\t%d", x, y);
}
