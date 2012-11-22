#include "substr.h"
#include <string.h>

#include "error.h"
#include "global.h"

/**
 * @brief get a sub string of s and put it in str
 *
 * @param s the whole string
 * @param str storing the substring
 */
void substr(const char *s, char *str)
{
    int i, j;
    int len;

    len = strlen(s);
    if (pos2 > 0 && pos2 < len) {
        len = pos2;
    }
    else if (pos2 > 0 && pos2 > len) {
        error("%s: string is too short\n", __func__);
    }

    for (i = pos1, j = 0; i < len; i++, j++) {
        str[j] = s[j];
    }

    str[j] = '\0';
}
