#include "readargs.h"
#include "readlines.h"
#include "writelines.h"
#include "error.h"
#include "numcmp.h"
#include "charcmp.h"
#include "global.h"

int main(int argc, const char *argv[])
{
    char *lineptr[LINES];/* pointer to text lines */
    int nlines;

    readargs(argc, argv);

    if ((nlines = readlines(lineptr, LINES)) < 0) {
        error("input too big to sort\n");
    }

    if (option & NUMERIC) {
        qsort(lineptr, nlines, sizeof *lineptr,  numcmp);
    }
    else {
        qsort(lineptr, nlines, sizeof *lineptr, charcmp);
    }

    writelines(lineptr, nlines, option & DECR);

    return 0;
}
