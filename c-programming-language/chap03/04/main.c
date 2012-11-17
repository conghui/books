#include <stdlib.h>
#include <string.h>

int main(void)
{
    return 0;
}

void itoa(int n, char *s)
{
    int i;
    int sign;
    char *reverse(char *buffer);

    sign = n;
    i = 0;

    do {
      s[i++] = abs(n % 10) + '0';  
    } while ((n /= 10 ) != 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
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

