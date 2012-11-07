#include <stdio.h>
#include <ctype.h>

#define IN 0
#define OUT 1

int main(void) {
    int c;
    int prev_stat;
    int curr_stat;

    prev_stat = OUT;

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            curr_stat = OUT;
        }
        else {
            curr_stat = IN;
            putchar(c);
        }

        if (prev_stat == IN && curr_stat == OUT) {
            putchar('\n');
        }

        prev_stat = curr_stat;
    }

    return 0;
}
