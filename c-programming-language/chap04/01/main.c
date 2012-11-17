#include <stdio.h>
#include <string.h>


static int strrindex(const char *s, const char *t);

int main(void)
{
    return 0;
}

static int strrindex(const char *s, const char *t)
{
    int i;

    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        int j;
        int k;
        for (j = i, k = 0; 
             s[j] == t[k] && s[j] != '\0' && t[k] != '\0';
             j++, k++)
        {
            ;
        }

        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }

    return -1;
}
