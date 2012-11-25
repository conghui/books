#include <stdio.h>
#include <stdlib.h>

#define MAXBOT  3   /* max # lines at bottom page  */
#define MAXHDR  5   /* max # lines at head of page */
#define MAXLINE 100 /* max # char in a line        */
#define MAXPAGE 66  /* max # line in a page        */
static int heading(const char *fname, int pageno);
static void fileprint(FILE *fp, const char *fname);

int main(int argc, const char **argv)
{
    FILE *fp;

    if (argc == 1) {
        fileprint(stdin, "");
    }
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "cannot open %s\n", *argv);
                exit(EXIT_FAILURE);
            }
            else {
                fileprint(fp, *argv);
                fclose(fp);
            }
        }
    }
    return 0;
}


static int heading(const char *fname, int pageno) {
    int ln = 3;

    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s page %d\n", fname, pageno);
    while (ln++ < MAXHDR) {
        printf("\n");
    }

    return ln;
}

static void fileprint(FILE *fp, const char *fname)
{
    int lineno;
    int pageno = 1;

    char line[MAXLINE];
    
    lineno = heading(fname, pageno++);

    while (fgets(line, MAXLINE, fp)) {
        if (lineno == 1) {
            printf("\f");
            lineno = heading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno > MAXPAGE - MAXBOT) {
            lineno = 1;
        }
    }

    fprintf(stdout, "\f");
}
