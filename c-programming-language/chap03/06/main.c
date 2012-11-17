#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* myitoa(int n, char *s, int w);

int main(void)
{
    char buf[BUFSIZ];
    puts(myitoa(128, buf, 5));
    return 0;
}

char *myitoa(int n, char *s, int w)
{
    int i;
    int sign;
    char *reverse(char *buffer);

    sign = n;
    i = 0;
    
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    while (i < w) {
        s[i++] = ' ';
    }

    s[i] = '\0';

    reverse(s);

    return s;
}


void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
char *reverse(char *buffer)
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

