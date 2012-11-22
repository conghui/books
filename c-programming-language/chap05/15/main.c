#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define NUMERIC 1   /* numeric sort                       */
#define REVERSE 2   /* revert sort                        */
#define FOLD    4   /* fold upper and lower case */
#define LINES   100 /* max # number of lines to be sorted */

static unsigned char option = 0;
static const char *proname;

static void writelines(char **lineptr, int nlines, int reverse);
static int readlines(char **lineptr, int nlines);
static int numcmp(const void *a, const void *b);
static int charcmp(const void *a, const void *b);
static int charicmp(const void *a, const void *b);

int main(int argc, char **argv)
{
    char *lineptr[LINES];   /* pointers to text line */
    int nlines;
    int c; 
    proname = argv[0];

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0]) != '\0') {
            switch (c) {
                case 'n':              /* numeric sort  */
                    option |= NUMERIC;
                    break;
                case 'r':              /* reversed sort */
                    option |= REVERSE;
                    break;
                case 'f':
                    option |= FOLD; /* fold sort */
                    break;
                default:
                    fprintf(stderr, "%s: illegal option: %c\n", proname, c);
                    fprintf(stderr, "usage: %s -nr \n", proname);
                    exit(EXIT_FAILURE);
            }
        }
    }

    if ((nlines = readlines(lineptr, LINES)) < 0) {
        fprintf(stderr, "input too big to sort\n");
        exit(EXIT_FAILURE);
    }

    /* now begin to sort */
    if (option & NUMERIC) {
        qsort(lineptr, nlines, sizeof *lineptr, numcmp);
    }
    else if (option & FOLD) {
        qsort(lineptr, nlines, sizeof *lineptr, charicmp);
    }
    else {
        qsort(lineptr, nlines, sizeof *lineptr, charcmp);
    }

    writelines(lineptr, nlines, option & REVERSE);

    int i;
    for (i = 0; i < nlines; i++) {
        free(lineptr[i]);
    }

    return 0;
}

/**
 * @brief write output lines
 *
 * @param lineptr array of pointers pointing to each line
 * @param nlines total # of lines
 * @param reverse if set, write in reversed order
 */
static void writelines(char **lineptr, int nlines, int reverse)
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

/**
 * @brief read line from stdin to lineptr
 *
 * @param lineptr buffer containing the lines
 * @param nlines max # of line to read in
 *
 * @return 
 */
static int readlines(char **lineptr, int nlines) {
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

static int numcmp(const void *a, const void *b)
{
    double v1;
    double v2;

    v1 = atof(*(const char **)a);
    v2 = atof(*(const char **)b);

    return v1 - v2;
}

static int charcmp(const void *a, const void *b) {
    const char *A = *(const char **)a;
    const char *B = *(const char **)b;

    for (; *A == *B; A++, B++) {
        if (*A == '\0') {
            return 0;
        }
    }

    return *A - *B;
}

static int charicmp(const void *a, const void *b) {
    const char *A = *(const char **)a;
    const char *B = *(const char **)b;

    for (; tolower(*A) == tolower(*B); A++, B++) {
        if (*A == '\0') {
            return 0;
        }
    }

    return tolower(*A) - tolower(*B);
}
