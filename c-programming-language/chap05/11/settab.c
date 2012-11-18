#include <stddef.h>
#include <stdlib.h>
#include "settab.h"

/**
 * @brief set tab stop in array tab
 *
 * @param argc argc from command line
 * @param argv argv from command line
 * @param tab array tab containting tab stop
 */
void settab(int argc, char **argv, char *tab)
{
    int i;
    int pos;

    if (argc <= 1) {                               /* default tab stops      */
        for (i = 1; i <= MAXLINE; i++) {
            tab[i] = (i % TABINC == 0) ? YES : NO;
        }
    }
    else {                                         /* user provide tab stops */
        for (i = 1; i <= MAXLINE; i++) {
            tab[i] = NO;                           /* turn off all tab stops */
        }

        while (*++argv != NULL) {                   /* walk through arg list  */
            pos = atoi(*argv);
            if (pos > 0 && pos <= MAXLINE) {
                tab[pos] = YES;
            }
        }

    }

}
