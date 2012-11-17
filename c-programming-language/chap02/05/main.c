#include <stdio.h>
#include <string.h>


static int any(const char *s1, const char *s2);

int main(void)
{
    const char *s2 = "1234567890";
    char buf[BUFSIZ];

    while (fgets(buf, BUFSIZ, stdin)) {
        printf("%d\n", any(buf, s2));
    }
    return 0;
}

/* return the index of the character that is in s1 and it is also in 
 * s2
 */
static int any(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++) {
        if (strchr(s2, s1[i])) {
            return i;
        }
    }

    return -1;
}
