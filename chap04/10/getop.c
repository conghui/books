#include <stdio.h>
#include <ctype.h>
#include "mygetline.h"
#include "getop.h"

#define MAXLINE 100
static int li = 0;
static char line[MAXLINE];

/**
 * @brief get next operator or numeric operand
 *
 * @param s buffer store the result
 *
 * @return signal indicating that it gets
 */
int getop(char *s)
{
    int c, i;

    if (line[li] == '\0') {
        if (mygetline(line, MAXLINE) == 0) {
            return EOF;
        }
        else {
            li = 0;
        }
    }

    /* skip the white space */
    while ((s[0] = c = line[li++]) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.') {
        return c;   /* not a number */
    }

    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = line[li++])) {
            ;
        }
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = line[li++]))
            ;
    }

    s[i] = '\0';
    li--;
    return NUMBER;
}
