#include "getword.h"
#include "comment.h"

int getword(char *word, size_t lim)
{
    int c;
    int d;
    char *w = word;

    while (isspace(c = getchar()) && c != '\n')
        ;

    if (c != EOF) {
        *w++ = c;
    }

    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; w++) {
            if (!isalpha(*w = getchar()) && *w != '_') {
                ungetc(*w, stdin);
                break;
            }
        }
    }
    else if (c == '\'' || c == '"') {
        for (; --lim > 0; w++) {
            if ((*w = getchar()) == '\\') {
                *++w = getchar();
            }
            else if (*w == c) {
                w++;
                break;
            }
            else if (*w == EOF) {
                break;
            }
        }
    }
    else if (c == '/') {
        if ((d = getchar()) == '*') {
            c = comment();
        }
        else {
            ungetc(d, stdin);
        }
    }

    *w = '\0';
    return c;
}
