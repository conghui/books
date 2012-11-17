#include <ctype.h>
#include <stdio.h>

double atof(char *s);

int main(void)
{
    char *buf = "  1.234e2";

    printf("%f\n", atof(buf));
    return 0;
}

double atof(char *s)
{
    int i;
    int sign;
    double val;
    double power;
    int exp;

    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        else {
            sign = 1;
        }
        i++;
    }

    for (val = 0; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
        power *= 10;
    }

    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        sign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '-' || s[i] == '+') {
            i++;
        }

        for (exp = 0; isdigit(s[i]); i++) {
            exp = exp * 10 + (s[i] - '0');
        }

        if (sign == 1) {
            while (exp-- > 0) {
                val *= 10;
            }
        }
        else {
            while (exp-- > 0) {
                val /= 10;
            }
        }
    }

    return val;
}
