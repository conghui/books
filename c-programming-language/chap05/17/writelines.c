#include <assert.h>
#include <stdio.h>

#include "writelines.h"

/**
 * @brief write output lines
 *
 * @param lineptr array of pointers pointing to each line
 * @param nlines total # of lines
 * @param reverse if set, write in reversed order
 */
void writelines(char **lineptr, int nlines, int reverse)
{
    int i;

    assert(lineptr);
    assert(nlines >= 0);

    if (reverse) {
        for (i = nlines - 1; i >= 0; i--) {
            fputs(lineptr[i], stdout);
        }
    }
    else {
        for (i = 0; i < nlines; i++) {
            fputs(lineptr[i], stdout);
        }
    }

}
