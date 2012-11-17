#include <stdio.h>
#include <string.h>

#define TAB_EXPAND 8
#define MAXLINE 1024

static void expand2(const char *buffer);

int main(void)
{
    char buffer[MAXLINE];
    
    while (fgets(buffer, MAXLINE, stdin) != NULL) {
        expand2(buffer);
    }
    return 0;
}

static void expand2(const char *buffer)
{
    int i;
    int len;

    len = strlen(buffer);

    for (i = 0; i < len; i += TAB_EXPAND) {
        int end;
        int j;

        end = i + TAB_EXPAND - 1;
        while (end >= i && buffer[end] == ' ') {
            end--;
        }

        end++;

        for (j = i; j < end && buffer[j] != '\0'; j++) {
            putchar(buffer[j]);
        }

        if (j < i + TAB_EXPAND && buffer[j] != '\0') {
            putchar('\t');
        }
    }

}
