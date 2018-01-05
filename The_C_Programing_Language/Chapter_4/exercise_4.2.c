#include <stdio.h>
#include <ctype.h>

/*
Extend  atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by  e or  E and an optionally signed exponent.
*/

double atof(char s[]);

int main() {
    char s[] = "123.45e-6";

    printf("%g\n", atof(s));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power, e;
    int i, sign, e_sign, e_val;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] = '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    e_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (e_val = 0; isdigit(s[i]); i++)
        e_val = 10 * e_val + (s[i] - '0');
    if (e_sign == -1) {
        for (e = 1.0; e_val > 0; e_val--) {
            e = e * 0.1;
        }
    } else {
        for (e = 1.0; e_val > 0; e_val--) {
            e = e * 10;
        }
    }
    return sign * val / power * e;
}
