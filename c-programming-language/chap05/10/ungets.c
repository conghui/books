#include <stdio.h>
#include <string.h>

#include "ungets.h"

/**
 * @brief put the string s back to stdin
 *
 * @param s the string to put back
 */
void ungets(const char *s)
{
    const char *pend = s + strlen(s) - 1;

    while (pend >= s) {
        ungetc(*pend--, stdin);
    }
}
