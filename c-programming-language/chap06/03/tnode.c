#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"

int noiseword(const char *w)
{
    static char *nw[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };

    int cond;
    int mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(*nw) + 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(w, nw[mid])) < 0) {
            high = mid - 1;
        }
        else if (cond > 0) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

linklist_t *lalloc(void)
{
    linklist_t *p;

    if ((p = malloc(sizeof(linklist_t))) == NULL) {
        fprintf(stderr, "memory is not enought\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

void treexprint(tnode_t *p)
{
    linklist_t *tmp;

    if (p == NULL) {
        return;
    }

    treexprint(p->left);
    printf("%10s: ", p->word);
    for (tmp = p->lines; tmp != NULL; tmp = tmp->ptr) {
        printf("%4d ", tmp->lnum);
    }
    printf("\n");

    treexprint(p->right);
}

void addln(tnode_t *p, int linenum)
{
    linklist_t *tmp;

    if (p == NULL) {
        return ;
    }

    for (tmp = p->lines; tmp->ptr != NULL && tmp->lnum != linenum;
            tmp = tmp->ptr)
    {
        ;
    }

    if (tmp->lnum != linenum) {
        tmp->ptr = lalloc();
        tmp->ptr->lnum = linenum;
        tmp->ptr->ptr = NULL;
    }
}

tnode_t *addtreex(tnode_t *p, char *w, int linenum) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0) {
        addln(p, linenum);
    }
    else if (cond < 0) {
        addln(p->left, linenum);
    }
    else {
        addln(p->right, linenum);
    }

    return p;
}

tnode_t *talloc(void)
{
    tnode_t *p;

    p = malloc(sizeof *p);
    if (p == NULL) {
        fprintf(stderr, "memory not enough\n");
        exit(EXIT_FAILURE);
    }

    return p;
}
