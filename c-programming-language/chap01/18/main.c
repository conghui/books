#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

static char *trim_end(char *buffer);

int main(void)
{
    char buffer[MAXLINE];

    while (fgets(buffer, MAXLINE, stdin) != NULL) {
        if (trim_end(buffer) != NULL) {
            fputs(buffer, stdout);
        }
    }

    return 0;
}

static char *trim_end(char *buffer)
{
    char *p;
    char *ret;

    p = strchr(buffer, '\n');
    if (p == NULL) {
        p = strchr(buffer, '\0');
    }

    p--;
    while (p >= buffer && (*p == ' ' || *p == '\t')) {
        p--;
    }

    if (p >= buffer) {
        *(++p) = '\n';
        *(++p) = '\0';
        ret = buffer;
    }
    else {
        ret = NULL;
    }

    return ret;
}
