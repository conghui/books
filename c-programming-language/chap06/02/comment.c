#include "comment.h"

/**
 * @brief skip over comment and return a character
 *
 * @return
 */
int comment(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '*') {
            if ((c = getchar()) == '/') {
                break;
            }
            else {
                ungetc(c, stdin);
            }
        }
    }

    return c;
}
