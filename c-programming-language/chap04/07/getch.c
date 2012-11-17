#include <string.h>
#include "getch.h"

static char buf[BUFSIZE];
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

/**
 * @brief push string back onto the buffer
 *
 * @param s string to be pushed back
 */
void ungets(const char *s) {
    size_t len;

    len = strlen(s);

    while (len > 0) {
        ungetch(s[--len]);
    }
}
