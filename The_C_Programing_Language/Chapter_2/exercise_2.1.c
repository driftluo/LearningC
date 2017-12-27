#include <stdio.h>
#include <limits.h>

void main() {
    printf("char bit: %d\t\n", CHAR_BIT);
    printf("signed char min: %d\tsigned char max: %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char max: %u\n\n", UCHAR_MAX);

    printf("signed short int min: %d\tsigned short int max: %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int max: %u\n\n", USHRT_MAX);

    printf("signed int min: %d\tsigned int max: %d\n", INT_MIN, INT_MAX);
    printf("unsigned int max: %u\n\n", UINT_MAX);

    printf("signed long int min: %ld\tsigned long int max: %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int max: %lu\n\n", ULONG_MAX);

    printf("signed long long int min: %lld\tsigned long long int max: %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long int max: %llu\n\n", ULLONG_MAX);
}
