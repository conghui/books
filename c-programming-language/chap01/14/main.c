#include <stdio.h>
#include <stdlib.h>

#define NUM_CHAR 128

static void readContent(char *num_char);
static int numDiffChars(char *num_char, int size);
static void initDiffChar(int *diff_char, char *num_char, int size);
static void draw(int *diff_char, int num_diff, char *num_char, int size);

int main(void)
{
    int *diff_char;
    int num_diff_chars;
    char num_char[NUM_CHAR] = {0};

    readContent(num_char);

    num_diff_chars = numDiffChars(num_char, NUM_CHAR);
    diff_char = malloc(num_diff_chars * sizeof *diff_char);
    initDiffChar(diff_char, num_char, NUM_CHAR);
    draw(diff_char, num_diff_chars, num_char, NUM_CHAR);

    return 0;
}

static void readContent(char *num_char)
{
    int c;

    while ((c = getchar()) != EOF) {
        num_char[c]++;
    }
}

static int numDiffChars(char *num_char, int size)
{
    int i;
    int sum;

    sum = 0;
    for (i = 0; i < size; i++) {
        if (num_char[i] > 0) {
            sum++;
        }
    }

    return sum;
}

static void initDiffChar(int *diff_char, char *num_char, int size)
{
    int i;
    int j;

    for (i = 0, j = 0; i < size; i++) {
        if (num_char[i] > 0) {
            diff_char[j] = i;
            j++;
        }
    }
}

static int max_value(char *num_char, int size) 
{
    int i;
    int max = num_char[0];

    for (i = 0; i < size; i++) {
        if (max < num_char[i]) {
            max = num_char[i];
        }
    }

    return max;
}
static void draw(int *diff_char, int num_diff, char *num_char, int size)
{
    int max;
    int i;
    int j;

    max = max_value(num_char, size);

    for (i = max; i > 0; i--) {
        for (j = 0; j < num_diff; j++) {
            if (num_char[diff_char[j]] >= i) {
                printf("%3c", '*');
                num_char[diff_char[j]]--;
            }
            else {
                printf("%3c", ' ');
            }
        }
        putchar('\n');
    }

    for (j = 0; j < num_diff; j++) {
        if (diff_char[j] == '\n') {
            printf(" \\n");
        }
        else {
            printf("%3c", diff_char[j]);
        }
    }
    putchar('\n');
}
