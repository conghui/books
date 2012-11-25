#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void filecomp(FILE *fp1, FILE *fp2);

int main(int argc, const char *argv[])
{
    FILE *fp1;
    FILE *fp2;

    if (argc != 3) {
        fprintf(stderr, "comp: need two file names\n");
        exit(EXIT_FAILURE);
    }

    if ((fp1 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "error: cannot open %s\n", *argv);
        exit(EXIT_FAILURE);
    }
    else if ((fp2 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "error: cannot open %s\n", *argv);
        exit(EXIT_FAILURE);
    }
    else {
        filecomp(fp1, fp2);
        fclose(fp1);
        fclose(fp2);
    }
    return 0;
}

static void filecomp(FILE *fp1, FILE *fp2) 
{
    char line1[BUFSIZ];
    char line2[BUFSIZ];
    const char *pl1;
    const char *pl2;

    do {
        pl1 = fgets(line1, BUFSIZ, fp1);
        pl2 = fgets(line2, BUFSIZ, fp2);

        if (pl1 == line1 && pl2 == line2) {
            if (strcmp(line1, line2) != 0) {
                printf("first difference at line\n");
                printf("%s\n", line1);
                pl1 = pl2 = NULL;
            }
        }
        else if (pl1 != line1 && pl2 == line2) {
            printf("end of first file at line\n");
            printf("%s\n", line2);
        }
        else if (pl1 == line1 && pl2 != line2) {
            printf("end of second file at line\n");
            printf("%s\n", line1);
        }

    } while (pl1 == line1 && pl2 == line2);
}

