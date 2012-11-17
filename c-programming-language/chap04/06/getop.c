#include <stdio.h>
#include "getop.h"

/*int getop(char *s)*/
/*{*/
    /*int i, c;*/

    /*while ((s[0] = c = getch()) == ' ' || c == '\t')*/
        /*;*/

    /*s[1] = '\0';*/

    /*if (!isdigit(c) && c != '.')*/
        /*return c;*/

    /*i = 0;*/
    /*if (isdigit(c)) {*/
        /*while (isdigit(s[++i] = c = getch()))*/
            /*;*/
    /*}*/

    /*if (c == '.') {*/
        /*while (isdigit(s[++i] = c =getch()))*/
            /*;*/
    /*}*/

    /*s[i] = '\0';*/
    /*if (c != EOF)*/
        /*ungetch(c);*/

    /*return NUMBER;*/
/*}*/

int getop(char *s)
{
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }

    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        }
        else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    if (c == '.') {
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
