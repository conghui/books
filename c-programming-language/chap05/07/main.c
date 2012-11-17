#include <stdio.h>
#include <string.h>

#define MAXLEN  1000    /* maximum length of line */
#define MAXSTOR 5000    /* size of available storage space */

/**
 * @brief read line from input to array
 *
 * @param lineptr[] array of pointers point to each line
 * @param linestor buffer store the whole data
 * @param maxlines maximum lines to be read in
 *
 * @return the number of lines read 
 */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    char buf[MAXLEN];
    char *storavail = linestor;
    int nline = 0;

    for (; nline < maxlines; nline++) {
        size_t len;

        if (fgets(buf, MAXLEN, stdin) == NULL) {
            break;
        }

        len = strlen(buf);
        /* test if there is enough space */
        if (storavail - linestor + len + 1 > MAXSTOR) {
            /* no space left, return -1 */
            return -1;
        }

        if (buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
            len--;
        }

        strcpy(storavail, buf);
        *lineptr++ = storavail;
        storavail += len + 1;
    }

    return nline;
}

int main(void)
{
    return 0;
}
