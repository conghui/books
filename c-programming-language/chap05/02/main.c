#include <ctype.h>
#include <stdio.h>

int getfloat(float *pf);

int main(void)
{
    float f;
    getfloat(&f);
    printf("%f\n", f);
    return 0;
}

/**
 * @brief eat the white space of the input stream
 */
static void ewspace(void) {
    char c;
    while (isspace(c = getchar())) {
        ;
    }

    if (c != EOF) {
        ungetc(c, stdin);
    }
}

int getfloat(float *pf)
{
    int c;
    int sign;
    int sawsign;
    long s = 0;
    int times = 1;

    ewspace();
    c = getchar();

    if (!isdigit(c) && c != '.' && c != '+' &&
            c != '-' && c != EOF)
    {
        ungetc(c, stdin);
        return 0;
    }

    sawsign = (c == '+' || c == '-');
    sign = (c == '-' ? -1 : 1);
    if (sawsign) {
        c = getchar();
    }

    if (!isdigit(c) && c != '.') {
        ungetc(c, stdin);
        if (sawsign) {
            ungetc(sign == -1 ? '-' : '+', stdin);
        }
        return 0;
    }

    if (isdigit(c)) {
        for (; isdigit(c); c = getchar()) {
            s = s * 10 + c - '0';
        }
    }

    if (c == '.') {
        for (c = getchar(); isdigit(c); c = getchar()) {
            s = s * 10 + c - '0';
            times *= 10;
        }
    }

    *pf = (double)s / (double)times * sign;

    if (c != EOF) {
        ungetc(c, stdin);
    }

    return c;
}
