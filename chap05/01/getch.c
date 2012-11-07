#include "getch.h"

static int buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetchar: too many characters\n");
    else
        buf[bufp++] = c;
}
