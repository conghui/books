#include <stdio.h>

static char *strcat(char *s, const char *t)
{
    char *p = s;
    
    /* reach the '\0' character */
    while (*p) {
        p++;
    }

    /* append t to the end of s, including the 
     * '\0' character*/
    while ((*p++ = *t++) != '\0') {
        ;
    }

    return s;
}

int main(void)
{
    char s[100] = "hello ";
    puts(strcat(s, "world"));

    return 0;
}
