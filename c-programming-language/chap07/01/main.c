#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int c;

    if (strcmp(*argv, "./lower") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    }
    else if (strcmp(*argv, "./upper") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    }
    else {
        while ((c = getchar()) != EOF) {
            putchar(c);
        }
    }

    return 0;
}
