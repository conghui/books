#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

static int htoi(const char *h);

int main(void) {
    char buf[BUFSIZ];
    
    while (fgets(buf, BUFSIZ, stdin)) {
        *(buf + strlen(buf) - 1) = '\0';
        printf("%d\n", htoi(buf));
    }
    return 0;
}

static int alphaToDigit(int c)
{
    int lc;

    lc = tolower(c);
    assert(lc >= 'a' && lc <= 'f');

    return lc - 'a' + 10;
}

static int hexToDigit(int c)
{
    if (isdigit(c)) {
        return c - '0';
    }
    else {
        return alphaToDigit(c);
    }
}

static int htoi(const char *h)
{
    int n;
    const char *p;

    n = 0;
    if (*h == '0' &&
        (*(h+1) == 'x' || *(h+1) == 'X'))
    {
        p = h+2;
    }
    else {
        p = h;
    }

    for (; *p != '\0'; p++) {
        n = n * 16 + hexToDigit(*p);
    }

    return n;
}
