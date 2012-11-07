#include <stdio.h>
#include <stdlib.h>

char *itoa(int n, char *s);

int main(void)
{
    char s[100];
    int i = 123456;
    int b = -123456;

    printf("%s\n", itoa(i, s));
    printf("%s\n", itoa(b, s));

    return 0;
}

char *itoa(int n, char *s)
{
    static int i = 0;

    if (n / 10) {
        itoa(n / 10, s);
    }
    else {
        i = 0;
        if (n < 0) {
            s[i++] = '-';
        }
    }

    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';

    return s;
}
