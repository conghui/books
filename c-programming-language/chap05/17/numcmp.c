#include <stdlib.h>
#include <stdio.h>

#include "numcmp.h"
#include "substr.h"

int numcmp(const void *v1, const void *v2)
{
    char buf[BUFSIZ];
    double ia;
    double ib;
    const char *a = *(const char **)v1;
    const char *b = *(const char **)v2;

    substr(a, buf);
    ia = atof(buf);
    substr(b, buf);
    ib = atof(buf);

    if (ia < ib) {
        return -1;
    } else if (ia > ib) {
        return 1;
    }
    else {
        return 0;
    }
}
