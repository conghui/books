#include <stdio.h>

int main(void)
{
    int prev;   /* previous character */
    int cur;    /* current character */

    prev = getchar();

    while (prev != EOF)
    {
        cur = getchar();

        if (!(prev == ' ' && cur == ' '))
        {
            putchar(prev);
            prev = cur;
        }
    }

    return 0;
}
