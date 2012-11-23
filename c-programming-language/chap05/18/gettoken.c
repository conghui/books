#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "global.h"

/**
 * @brief return next token
 *
 * @return
 */
int gettoken(void)
{
    int c;
    char *p = token;

    if (prevtoken == YES) {
        prevtoken = NO;
        return tokentype;
    }

    while ((c = getchar()) == ' ' || c == '\t') {
        ;
    }

    if (c == '(') {
        if ((c = getchar()) == ')') {
            strncpy(token, "()", MAXTOKEN);
            return tokentype = PARENS;
        }
        else {
            ungetc(c, stdin);
            return tokentype = '(';
        }
    }
    else if (c == '[') {
        for (*p++ = c; (*p++ = getchar()) != ']'; ) {
            ;
        }

        *p        = '\0';
        tokentype = BRACKETS;
        return tokentype;
    }
    else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getchar()); ) {
            *p++ = c;
        }
        *p = '\0';
        ungetc(c, stdin);
        return tokentype = NAME;
    }
    else {
        return tokentype = c;
    }
}
