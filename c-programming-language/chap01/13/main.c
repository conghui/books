#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WORD_MAX_LENGTH 11
#define HISTORM_MAX_LENGTH 14
#define IN 2
#define OUT 3
#define TRUE 1
#define FALSE 0

static void zeroArray(int *a, int size);
static void readWords(int *word_len, int max_len, int *overflow);
static void draw_horizontal_histogram(const int *word_len, int size);
static void draw_vertical_histogram(int *word_len, int size);

int main(void)
{
    int word_len[WORD_MAX_LENGTH];
    int overflow;

    overflow = 0;
    zeroArray(word_len, WORD_MAX_LENGTH);
    readWords(word_len, WORD_MAX_LENGTH, &overflow);
    draw_horizontal_histogram(word_len, WORD_MAX_LENGTH);

    printf("\n -------------------------------- \n\n");
    draw_vertical_histogram(word_len, WORD_MAX_LENGTH);
    printf("num of overflow: %d\n", overflow);

    return 0;

}

static int max_value(const int *word_len, int size)
{
    int i;
    int max = word_len[0];

    for (i = 1; i < size; i++) {
        if (max < word_len[i]) {
            max = word_len[i];
        }
    }

    return max;
}
static int scaled(int n, int max)
{
    double r = (double)HISTORM_MAX_LENGTH * n / max;
    if (r > 0 && r < 1) {
        r = 1;
    }

    return (int)r;
}

static void draw_tag(int n)
{
    for (; n > 0; n--) {
        putchar('*');
    }
}

static void draw_horizontal_histogram(const int *word_len, int size)
{
    int i;
    int num_tag;
    int max;

    max = max_value(word_len, size);

    printf("%10s %2s %5s\n", "word_len", "-", "count");
    for (i = 1; i < size; i++) {
        printf("%6d %6s %3d: ", i, "-", word_len[i]);
        num_tag = scaled(word_len[i], max);
        draw_tag(num_tag);
        putchar('\n');
    }

}

static void zeroArray(int *a, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        a[i] = 0;
    }
}

static void readWords(int *word_len, int max_len, int *overflow)
{
    int state;
    int prev_state;
    int c;
    int count;

    prev_state = OUT;
    count = 0;

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            state = OUT;
        }
        else {
            state = IN;
            count++;
        }

        if (prev_state == IN && state == OUT) {
            if (count < max_len) {
                word_len[count]++;
            }
            else {
                (*overflow)++;
            }
            count = 0;
        }

        prev_state = state;
    }

}

static void draw_vertical_histogram(int *word_len, int size)
{
    int *scaled_word_len;
    int i;
    int max;
    int scaled_max;

    scaled_word_len = malloc(size * sizeof *scaled_word_len);
    max = max_value(word_len, size);

    for (i = 0; i < size; i++) {
        scaled_word_len[i] = scaled(word_len[i], max);
    }

    scaled_max = max_value(scaled_word_len, size);
    for (i = scaled_max; i > 0; i--) {
        int j;
        for (j = 1; j < WORD_MAX_LENGTH; j++) {
            if (scaled_word_len[j] >= i) {
                scaled_word_len[j]--;
                printf("%3c", '*');
            }
            else {
                printf("%3c", ' ');
            }
        }
        putchar('\n');
    }

    for (i = 1; i < size; i++) {
        printf("%3d", i);
    }
    putchar('\n');
}
