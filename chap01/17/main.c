#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 10

static int mygetline(char **buffer, int *maxline);

int main(void) 
{
    int buffersize;
    char *buffer;
    int count;

    buffersize = 2;
    buffer = malloc(buffersize * sizeof *buffer);

    while ((count = mygetline(&buffer, &buffersize)) > 0) {
        if (count > MAXLINE) {
            fputs(buffer, stdout);
        }
    }
    return 0;
}

static int mygetline(char **buffer, int *maxline)
{
    int i;
    int c;

    for (i = 0; (c = getchar()) != '\n' && c != EOF; i++)
    {
        if (i >= *maxline - 2) { 
            *maxline *= 2;
            *buffer = realloc(*buffer, *maxline);
        }

        (*buffer)[i] = c;
    }

    if (c == '\n') {
        (*buffer)[i] = '\n';
        i++;
        (*buffer)[i] = '\0';
    }

    return i;
}
