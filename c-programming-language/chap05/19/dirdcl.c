#include <string.h>

#include "dirdcl.h"
#include "global.h"
#include "errmsg.h"
#include "gettoken.h"
#include "dcl.h"

void dirdcl(void)
{
    int type;

    if (tokentype == '(') { /* (dcl) */
        dcl();
        if (tokentype != ')') {
            errmsg("error: missing )\n");
        }
    } else if (tokentype == NAME) { /* variable name */
        strncpy(name, token, MAXTOKEN);
    }
    else {
        errmsg("error: expected name of (dcl)\n");
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strncat(out, " function returning",
                    MAXTOKEN - strlen(out) - 1);
        }
        else {
            strncat(out, " array", MAXTOKEN - strlen(out) - 1);
            strncat(out, token, MAXTOKEN - strlen(out) - 1);
            strncat(out, " of", MAXTOKEN - strlen(out));
        }
    }
}
