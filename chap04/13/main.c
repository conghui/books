#include <stdio.h>
#include <string.h>


char *reverse(char *s);

int main(void)
{
    char buf[] = "123456";

    puts(reverse(buf));
    return 0;
}


char *reverse(char *s) {
    void reverser(char *s, size_t i, size_t len);

    reverser(s, 0, strlen(s));

    return s;
}

void reverser(char *s, size_t i, size_t len)
{
    int c;
    size_t j;

    j = len - (i + 1);

    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }

}
