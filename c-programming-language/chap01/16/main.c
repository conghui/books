#include <stdio.h>

#define MAXLINE 5

int mygetline(char *s, int lim);
void copy(char *to, char *from);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("len:      %d\n" 
               "striing:  %s\n", 
               max, longest);
    }

    return 0;
}

int mygetline(char *s, int lim)
{
    int c, i, j;

    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 2) {
            s[j] = c;
            j++;
        }
    }

    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }

    s[j] = '\0';

    return i;
}

void copy(char *to, char *from)
{
    int i;

    for (i = 0; (to[i] = from[i]) != '\0'; i++) {
        ;
    }
}
