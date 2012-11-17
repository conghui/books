#include <string.h>
#include <stdlib.h>

int main(void)
{
    return 0;
}

static void itob(int n, char *s, int b)
{
    int i;
    int sign;
    char *reverse(char *buffer);

    i = 0;
    sign = n;

    do {
        int j;

        j = abs(n % b);
        s[i++] = (n > 9) ? n - 10 + 'A' : j;
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
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
