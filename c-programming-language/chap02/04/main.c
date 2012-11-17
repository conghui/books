#include <stdio.h>
#include <string.h>

static char *squeeze(char *s1, const char *s2);

int main(void)
{
    const char *s2 = "0123456789";
    char buf[BUFSIZ];

    while (fgets(buf, BUFSIZ, stdin)) {
        fputs(squeeze(buf, s2), stdout);
    }
    return 0;
}

static char *squeeze(char *s1, const char *s2)
{
    int i, j;

    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        if (!strchr(s2, s1[i])) {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';

    return s1;
}
