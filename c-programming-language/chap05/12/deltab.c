#include <stdio.h>

#include "deltab.h"
#include "tabpos.h"

/**
 * @brief replace tab with blanks
 *
 * @param tab array of stop tabs
 */
void deltab(char *tab)
{
    int c;
    int pos;

    for (pos = 1; (c = getchar()) != EOF; pos++) {
        if (c == '\t') {
            do {
                putchar(' ');
            } while (tabpos(pos++, tab) != YES);
        }

        if (c == '\n') {
            pos = 0;
        }

        putchar(c);
    }
}
