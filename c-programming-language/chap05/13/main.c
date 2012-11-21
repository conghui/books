#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10  /* default number of line to print */
#define LINES    100 /* max # of lines to print         */
#define MAXLEN   100 /* max length of an input line     */
static void error(const char *fmt, ...);

int main(int argc, char **argv)
{
    char *p;
    char *buf;            /* pointer to large buffer */
    char *bufend;         /* end of the buffer       */
    char line[MAXLEN];    /* current input line      */
    char *lineptr[LINES]; /* pointers to lines read  */

    int first, i, last, len, n, nlines;

    /* determine # of lines to print */
    if (argc == 1) { /* no argument, default lines*/
        n = DEFLINES;
    }
    else if (argc == 2 && *argv[1] == '-') {
        n = atoi(argv[1] + 1);
    }
    else {
        error("usage: %s [-n]\n", argv[0]);
    }

    if ( n < 1 || n > LINES) { /* unreachable value */
        n = LINES; 
    }

    /* init array */
    for (i = 0; i < LINES; i++) {
        lineptr[i] = NULL;
    }

    /* allocate buffer */
    if ((p = buf = malloc(LINES * MAXLEN * sizeof *buf)) == NULL)  {
        error("error: not enough memory!\n");
    }

    bufend = buf + LINES * MAXLEN;
    first  = 0;
    last   = 0;

    for (nlines = 0; fgets(line, MAXLEN, stdin) != NULL; nlines++) {
        len = strlen(line);

        if (p + len + 1 >= bufend) { /* not enough space */
            p = buf; /* reuse the buffer */
        }

        strncpy(p, line, len + 1);
        lineptr[nlines] = p;
        p              += len + 1;

        if (++last >= LINES) {
            last = 0; /* ptrs to buffer wrap around */
        }
    }

    if (n > nlines) { /* req. line > rec. line */
        n = nlines;
    }

    first = last - n;
    if (first < 0) {
        first += LINES;
    }

    for (i = first; n-- > 0; i = (i+1) % LINES) {
        fputs(lineptr[i], stdout);
    }

    return 0;
}

static void error(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    exit(EXIT_FAILURE);
}
