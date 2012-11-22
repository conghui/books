#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "readlines.h"
int readlines(char **lineptr, int nlines);

/**
 * @brief read line from stdin to lineptr
 *
 * @param lineptr buffer containing the lines
 * @param nlines max # of line to read in
 *
 * @return
 */
int readlines(char **lineptr, int nlines) {
    int count;
    char buffer[BUFSIZ];

    assert(lineptr);

    for (count = 0;
         count < nlines && fgets(buffer, BUFSIZ, stdin) != NULL;
         count++)
    {
        lineptr[count] = malloc((strlen(buffer) + 1) * sizeof *lineptr[count]);

        if (lineptr[count] == NULL) {
            fprintf(stderr, "%s: no enought memory\n", __func__);
            exit(EXIT_FAILURE);
        }

        strncpy(lineptr[count], buffer, strlen(buffer) +  1);
    }

    if (count >= nlines) { /* not enought space  */
        count = -1;
    }

    return count;
}
