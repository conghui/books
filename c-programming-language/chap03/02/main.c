#include <string.h>
#include <stdio.h>

#define NUL '\0'

static char *escape(char *s, const char *t);
static char *rescape(char *s, const char *t);

int main(void)
{
    char buf[BUFSIZ] = "DD: ";
    const char *s = "hello\\tworld\\nI am here\\n";

    fputs(rescape(buf, s), stdout);

    return 0;
}

static char *escape(char *s, const char *t)
{
    char *p1;
    const char *p2;

    p1 = strchr(s, '\0');
    p2 = t;

    for (; *p2 != '\0'; p1++, p2++) {
        switch (*p2) {
            case '\t':
                *p1 = '\\';
                p1++;
                *p1 = 't';
                break; 
            case '\n':
                *p1 = '\\';
                p1++;
                *p1 = 'n';
                break;
            default:
                *p1 = *p2;
                break;
        }
    }

    *p1 = '\0';

    return s;
}

static char *rescape(char *s, const char *t)
{
    char *p1;
    const char *p2;

    p1 = strchr(s, NUL);
    p2 = t;

    for (; *p2 != NUL; p1++, p2++) {
        if (*p2 == '\\') {
            switch (*(p2 + 1)) {
                case 't':
                    p2 = p2 + 1;
                    *p1 = '\t';
                    break;
                case 'n':
                    p2 = p2 + 1;
                    *p1 = '\n';
                    break;
                default:
                    break;
            }
        }
        else {
            *p1 = *p2;
        }
    }

    *p1 = NUL;

    return s;
}
