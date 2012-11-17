#include <string.h>
#include <stdio.h>

#define NUL '\0'

#define DIGITS "0123456789"
#define LOW_ALPHA "abcdefghijklmnopqrstuvwxyz"
#define UPPER_ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHA LOW_ALPHA UPPER_ALPHA
#define ALPHA_DIGIT ALPHA DIGITS

static char *expand(const char *s1, char *s2);

int main(void)
{
    char buf[BUFSIZ];
    const char *s = "-a-zA-Z0-9-";

    puts(expand(s, buf));
    return 0;
}

static char *expand(const char *s1, char *s2)
{
    const char *p1;
    char *p2begin;

    p2begin = s2;
    p1 = strpbrk(s1, ALPHA_DIGIT);

    while (p1 != NULL) {
        int begin;
        int end;
        char *p3;
        int i;

        p3 = strpbrk(p1 + 1, ALPHA_DIGIT);
        begin = *p1;
        end = *p3;

        for (i = 0; i <= end - begin; i++) {
            *s2++ = begin + i;
        }

        p1 = strpbrk(p3 + 1, ALPHA_DIGIT);
    }

    *s2 = NUL;

    return p2begin;
}
