#include <string.h>
#include <ctype.h>

#include "charcmp.h"
#include "global.h"


int charcmp(const void *v1, const void *v2)
{
    const char *s = *(const char **)v1;
    const char *t = *(const char **)v2;

    int fold = option & FOLD ? 1 : 0;
    int dir  = option & DIR  ? 1 : 0;

    size_t i = pos1;
    size_t j = i;
    size_t endpos;

    int a, b;

    if (pos2 > 0) {
        endpos = pos2;
    }
    else if ((endpos = strlen(s)) > strlen(t)) {
        endpos = strlen(t);
    }

    do {
        if (dir) {
            while (i < endpos && !isalnum(*s) &&
                    s[i] != ' ' && s[i] != '\0') {
                i++;
            }

            while (j < endpos && !isalnum(*t) &&
                    t[j] != ' ' && t[j] != '\0') {
                j++;
            }
        }

        a = fold ? tolower(s[i]) : s[i];
        i++;
        b = fold ? tolower(t[j]) : t[j];
        j++;

        if (a == b && a == '\0') {
            return 0;
        }
    } while (a == b && i < endpos && j < endpos);

    return a - b;
}
