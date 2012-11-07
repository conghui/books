#include <stdio.h>

/* This program is to count the number of space, tab, and new line
 * character */

int main(void) {
    int n_space;    /* the number of space */
    int n_tab;      /* the number of tab */
    int n_nl;       /* the number of new line character */
    int c;

    n_space = n_tab = n_nl = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                n_space++;
                break;
            case '\t':
                n_tab++;
                break;
            case '\n':
                n_nl++;
                break;
            default:
                break;
        }
    }

    printf("# space: %d\n"
           "# tab  : %d\n"
           "# new line: %d\n",
           n_space, n_tab, n_nl);

    return 0;
}
