#include <stdio.h>
#include <string.h>
#include "gettoken.h"
#include "global.h"
#include "dcl.h"

static char datatype[MAXTOKEN];

int main(void)
{
    while (gettoken() != EOF) {
        strncpy(datatype, token, MAXTOKEN);
        out[0] = '\0';
        dcl();

        if (tokentype != '\n') {
            fprintf(stderr, "syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }

    return 0;
}
