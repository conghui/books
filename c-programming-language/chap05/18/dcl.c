#include <string.h>
#include "gettoken.h"
#include "dirdcl.h"
#include "global.h"

void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';) {
        ns++;
    }

    dirdcl();
    while (ns-- > 0) {
        strncat(out, " pointer to", MAXTOKEN - strlen(out) - 1);
    }
}
