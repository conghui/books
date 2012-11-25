#include <string.h>

#include "nlist.h"
#include "getword.h"

#define MAXWORD 100

static void skipblanks(void);
static void error(int c, const char *s);
static void getdef(void);
static void ungets(const char *s);

int main(void)
{
    char w[MAXWORD];
    nlist_t *p;

    while (getword(w, MAXWORD) != EOF) {
        if (strcmp(w, "#") == 0) {
            getdef();
        }
        else if (!isalpha(w[0])) {
            printf("%s", w);
        }
        else if ((p = lookup(w)) == NULL) {
            printf("%s", w);
        }
        else {
            ungets(p->defn);
        }
    }
    return 0;
}

static void skipblanks(void)
{
    int c;

    while ((c = getchar()) == ' ' || c == '\t') {
        ;
    }

    ungetc(c, stdin);
}

static void error(int c, const char *s)
{
    fprintf(stderr, "error: %s\n", s);

    while (c != EOF && c != '\n') {
        c = getchar();
    }
}

static void getdef(void)
{
    int  i;
    char def[MAXWORD];
    char dir[MAXWORD];
    char name[MAXWORD];

    skipblanks();
    if (!isalpha(getword(dir, MAXWORD))) {
        error(dir[0], "getdef: expecting a directive after #");
    }
    else if (strcmp(dir, "define") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD))) {
            error(name[0], "getdef: non-alpha-name expected");
        }
        else {
            skipblanks();
            for (i = 0; i < MAXWORD - 1; i++) {
                if ((def[i] = getchar()) == EOF || def[i] == '\n') {
                    break;
                }
            }
            def[i] = '\0';
            if (i <= 0) {
                error('\n', "getdef: incomplete define");
            }
            else {
                install(name, def);
            }
        }
    }
    else if (strcmp(dir, "undef") == 0) {
        skipblanks();

        if (!isalpha(getword(name, MAXWORD))) {
            error(name[0], "getdef: non-alpha in undef");
        }
        else {
            undef(name);
        }
    }
    else {
        error(dir[0], "getdef: expecting a directive after #");
    }
}

static void ungets(const char *s)
{
    size_t len = strlen(s);
    const char *pe = s + len - 1;

    for (; ; ) {
        ungetc(*pe, stdin);
        if (pe == s) {
            break;
        }
        pe--;
    }
}
