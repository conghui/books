#include "getch.h"

static char buf = 0;

int getch(void)
{
    int c;

    if (buf != 0) { /* a char in the buffer */
        c = buf;
        buf = 0;    /* now nothing in the buffer */
    }
    else {
        c = getchar();
    }

    return c;
}

void ungetch(int c)
{
    if (buf == 0) {
        fprintf(stderr, "%s: too many characters.\n", __func__);
    }
    else {
        buf = c;
    }
}
