#include <stdio.h>

/*
Write a program to print the corresponding Celsius to Fahrenheit table.
*/

void main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("celsius fahr\n");
    printf("----------\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius / (5.0/9.0) + 32.0;
        printf("%3.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
