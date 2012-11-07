#include <stdio.h>
#include <string.h>
#include "getop.h"

/**
 * @brief get next operator, numeric operand, or math function
 *
 * @param s a buffer that store the op
 *
 * @return the signal indicating what it gets
 */
int getop(char *s)
{
    int c, i;

    /* skip the white space */
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';
    i = 0;

    if (islower(c)){    /* command or name */
        while (islower(s[++i] = c = getch())) {
            ;
        }
        s[i] = '\0';
        if (c != EOF) {
            ungetch(c);  /* went one char too far */
        }

        if (strlen(s) > 1) {
            return NAME;    /* >1 char, it is a name */
        }
        else {
            return c;       /* it may be a command */
        }
    }

    if (!isdigit(c) && c != '.') {
        return c;       /* not a number */
    }

    if (isdigit(c)) {   /* collect integer part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    if (c == '.') {     /* collect fraction part */
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}
