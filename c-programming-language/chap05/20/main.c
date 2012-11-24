#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "gettoken.h"
#include "global.h"
#include "nexttoken.h"

int main(void)
{
    int type;
    char tmp[MAXTOKEN];

    while (gettoken() != EOF) {
        strncpy(out, token, MAXTOKEN);
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS) {
                strncat(out, token, MAXTOKEN - strlen(token) - 1);
            }
            else if (type == '*') {
                if ((type = nexttoken()) == PARENS ||
                        type == BRACKETS) {
                    sprintf(tmp, "(*%s)", out);
                }
                else {
                    sprintf(tmp, "*%s", out);
                }
                strncpy(out, tmp, MAXTOKEN);
            }
            else if (type == NAME) {
                sprintf(tmp, "%s %s", token, out);
                strncpy(out, tmp, MAXTOKEN);
            }
            else {
                fprintf(stderr, "invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }

    return 0;
}
