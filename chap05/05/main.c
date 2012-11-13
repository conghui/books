#include <stdio.h>

static int strncmp(const char *s, const char *t, size_t n);
static char *strncpy(char *dest, const char *src, size_t n);
static char *strncat(char *dest, const char *src, size_t n);

int main(void)
{
    return 0;
}

static char *strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }

    return dest;
}

static char *strncat(char *dest, const char *src, size_t n)
{
    size_t strlen(const char *s);

    char *p = dest + strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        p[i] = src[i];
    }

    p[i] = '\0';

    return dest;
}

static int strncmp(const char *s, const char *t, size_t n)
{
    for (; *s == *t; s++, t++) {
        if (*s == '\0' || --n <= 0) {
            return 0;
        }
    }

    return *s - *t;
}
