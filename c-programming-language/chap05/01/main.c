#include <ctype.h>
#include "getch.h"

int main(void)
{
    return 0;
}

int getint(int *pn)
{
    int c;
    int sawsign;
    int sign;

    /* skip the white space */
    while (isspace(c = getch())) {
        ;
    }

    if (!isdigit(c) && c != '+' &&
            c != '-' && c != EOF)
    {
        ungetch(c); /* not a number */
        return 0;
    }

    sign = (c == '-' ? -1 : 1);
    sawsign = (c == '+' || c == '-');
    if (sawsign) {
        c = getch();    /* get a char follow the sign */
    }

    if (!isdigit(c)) {
        ungetch(c);
        if (sawsign) {
            int cc;
            cc = sign == -1 ? '-' : '+';
            ungetch(cc); /* put the sign back to stream */
        }
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + c - '0';   /* get the value */
    }

    *pn *= sign;    /* multiply the sign */

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}
