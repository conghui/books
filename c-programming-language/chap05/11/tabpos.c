#include "tabpos.h"

/**
 * @brief determine if pos is set at a tab stop
 *
 * @param pos the position
 * @param tab tab stop table
 *
 * @return if set, return YES(1), else NO(0)
 */
int tabpos(int pos, const char *tab)
{
    if (pos > MAXLINE) {
        return YES;
    }

    return *(tab + pos);
}
