#include <ctype.h>
#include <stdio.h>
#include "getop.h"

static void skip_white_sp();

/**
 * @brief get operand or operator from stdin
 *
 * @param s stuff got from stdin
 *
 * @return indicating what it gets
 */
int getop(char *s)
{
    char c;

    skip_white_sp();

    /* get first non-space char to determine what it is */
    c = *s = getchar();

    /* not a digit */
    if (!isdigit(*s) && *s != '.' && *s != '+' && *s != '-') {
        *(s+1) = '\0';
        return *s;
    }

    if (*s == '+' || *s == '-') {
        c = getchar();
        if (!(isdigit(c) || c == '.')) {
            /* not a digit either */
            ungetc(c, stdin);
            *(s+1) = '\0';
            return *s;
        }
        else {
            *++s = c;   /* put it into s */
        }
    }

    /* now it is a digit, first query the integral part */
    while (isdigit(c)) {
        c = *++s = getchar();
    }

    /* if we meet the point, then continute scanning */
    if (*s == '.') {
        while (isdigit(*++s = getchar())) {
            ;
        }
    }

    /* now we reach the end */
    if (*s != EOF) {
        ungetc(*s, stdin);
    }
    *s = '\0';

    return NUMBER;
}

/**
 * @brief skip white space of stin
 */
static void skip_white_sp()
{
    int c;

    while ((c = getchar()) != EOF && isspace(c))
    {
        ;
    }

    if (c != EOF)
    {
        ungetc(c, stdin);
    }
}
