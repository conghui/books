#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXCEPT 01
#define NUMBER 02

#define MAXLINE 100

unsigned char option = 0;
void fpat(FILE *fp, const char *fname, const char *pattern);

int main(int argc, const char *argv[])
{
    char pattern[MAXLINE];
    int c;
    FILE *fp;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0]) != '\0') {
            switch (c) {
                case 'x':
                    option |= EXCEPT;
                    break;
                case 'n':
                    option |= NUMBER;
                    break;
                default:
                    fprintf(stderr, "find: illegal option: %c\n", c);
                    exit(EXIT_FAILURE);
                    break;
            }
        }
    }

    if (argc >= 1) {
        strncpy(pattern, *argv, MAXLINE);
    }
    else {
        fprintf(stderr, "usage: find [-x] [-n] pattern [file ...]\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 1) {
        fpat(stdin, "", pattern);
    }
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "find: cannot open %s\n", *argv);
                exit(EXIT_FAILURE);
            }
            else {
                fpat(fp, *argv, pattern);
                fclose(fp);
            }
        }
    }
    return 0;
}

void fpat(FILE *fp, const char *fname, const char *pattern)
{
    char line[MAXLINE];
    unsigned long linenum = 0;
    int except = option & EXCEPT ? 1 : 0;

    while (fgets(line, MAXLINE, fp)) {
        ++linenum;
        if ((strstr(line, pattern) != NULL) != except) {
            if (*fname) {
                printf("%s - ", fname);
            }
            if (option & NUMBER) {
                printf("%lu: ", linenum);
            }
            printf("%s", line);
        }
    }
}
