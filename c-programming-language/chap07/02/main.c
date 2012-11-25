#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100 /* max # of chars in a line */
#define OCTLEN  6   /* length of an octal value */
static int inc(int pos, int n);


int main(void)
{
    int c;
    int pos;

    pos = 0;

    while ((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ' ) {
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);

            if (c == '\n') {
                pos = 0;
                putchar('\n');
            }
        }
        else {
            pos = inc(pos, OCTLEN);
            putchar(c);
        }
    }
    return 0;
}

static int inc(int pos, int n)
{
    if (pos + n < MAXLINE) {
        return pos + n;
    }
    else {
        putchar('\n');
        return n;
    }
}   
