#include <stdio.h>
#include "mygetline.h"

int mygetline(char *s, int lim)
{
    int c, i, j;

    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 2) {
            s[j] = c;
            j++;
        }
    }

    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }

    s[j] = '\0';

    return i;
}
