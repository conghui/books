#include <stdlib.h>

#include "esettab.h"

void esettab(int argc, char **argv, char *tab)
{
    int i;
    int pos;
    int inc;

    if (argc <= 1) { /* use the default setting */
        for (i = 1; i <= MAXLINE; i++) {
            tab[i] = (i % TABINC == 0) ? YES : NO;
        }
    }
    else if (argc == 3 && *argv[1] == '-'
             && *argv[2] == '+') { /* user provided */
        pos = atoi(argv[1] + 1);
        inc = atoi(argv[2] + 1);

        for (i = 1; i <= MAXLINE; i++) {
            if (i != pos) {
                tab[i] = NO;
            }
            else {
                tab[i] = YES;
                pos   += inc;
            }
        }
    }
    else {
        for (i = 1; i <= MAXLINE; i++) {
            tab[i] = NO;
        }

        while (*++argv != NULL) {
            pos = atoi(*argv);
            if (pos > 0 && pos <= MAXLINE) {
                tab[pos] = YES;
            }
        }
    }
}
