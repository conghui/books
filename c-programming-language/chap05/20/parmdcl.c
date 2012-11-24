#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "global.h"
#include "dcl.h"
#include "errmsg.h"
#include "parmdcl.h"
#include "gettoken.h"

static int typespec(void);
static int typequal(void);
static int compare(const void *l, const void *r);

void parmdcl(void)
{
    do {
        dclspec();
    } while (tokentype == ',');

    if (tokentype != ',') {
        errmsg("missing ) in parameter declaration\n");
    }
}

void dclspec(void)
{
    char tmp[MAXTOKEN];

    tmp[0] = '\0';
    gettoken();

    do {
        if (tokentype != NAME) {
            prevtoken = YES;
            dcl();
        }
        else if (typespec() == YES) {
            strncat(tmp, " ", MAXTOKEN - strlen(tmp) - 1);
            strncat(tmp, token, MAXTOKEN - strlen(tmp) - 1);
            gettoken();
        }
        else if (typequal() == YES) {
            strncat(tmp, " ", MAXTOKEN - strlen(tmp) - 1);
            strncat(tmp, token, MAXTOKEN - strlen(tmp) - 1);
            gettoken();
        }
        else {
            errmsg("unknown type in parameter list\n");
        }
    } while (tokentype != ',' && tokentype != ')');

    strncat(out, tmp, MAXTOKEN - strlen(tmp) - 1);
    if (tokentype == ',') {
        strncat(out, ",", MAXTOKEN - strlen(",") - 1);
    }
}

static int typespec(void)
{
    static char *types[] = {
        "char",
        "int",
        "void"
    };

    char *pt = token;

    if (bsearch(&pt, types, sizeof(types) / sizeof *types,
                sizeof *types, compare) == NULL) {
        return NO;
    }

    return YES;
}

static int typequal(void)
{
    static char *typeq[] = {
        "const",
        "volatile"
    };

    char *pt = token;

    if (bsearch(&pt, typeq, sizeof(typeq) / sizeof *typeq,
                sizeof *typeq, compare) == NULL) {
        return NO;
    }

    return YES;
}

static int compare(const void *l, const void *r)
{
    const char *a = *(const char **)l;
    const char *b = *(const char **)r;

    return strcmp(a, b);
}
