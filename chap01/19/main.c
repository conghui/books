#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

static char *reverse(char *buffer);

int main(void)
{
    char buffer[MAXLINE];

    while (fgets(buffer, MAXLINE, stdin) != NULL) {
        fputs(reverse(buffer), stdout);
    }

    return 0;
}

static void swap(char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static char *reverse(char *buffer)
{
    char *first;
    char *last;

    first = buffer;
    last = strchr(buffer, '\0') - 1;

    if (*last == '\n') {
        last--;
    }

    while (last > first) {
        swap(first, last);
        last--;
        first++;
    }

    return buffer;
}
