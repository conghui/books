#include <stdio.h>

#define TAB_EXPAND 4

int main(void)
{
    char c;
    int pos;

    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int i;
            int nb;

            nb = TAB_EXPAND - (pos - 1) % TAB_EXPAND;
            for (i = 0; i < nb; i++) {
                putchar(' ');
                pos++;
            }
        }
        else if (c == '\n') {
            putchar(c);
            pos = 1;
        }
        else {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}
