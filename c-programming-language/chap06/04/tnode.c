#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"

#define NDISTINCT   1000

tnode_t *list[NDISTINCT];
int      ntn = 0;

static int numcmp(const void *l, const void *r);

tnode_t *addtree(tnode_t *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) < 0) {
        p->left = addtree(p->left, w);
    }
    else if (cond == 0) {
        p->count++;
    }
    else {
        p->right = addtree(p->right, w);
    }

    return p;
}

tnode_t *talloc(void)
{
    tnode_t *p = malloc(sizeof *p);

    if (p == NULL) {
        fprintf(stderr, "not enough memory\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

void treestore(tnode_t *p)
{
    if (p != NULL) {
        treestore(p->left);

        if (ntn < NDISTINCT) {
            list[ntn++] = p;
        }

        treestore(p->right);
    }
}

void sortlist(void) {
    qsort(list, ntn, sizeof *list, numcmp);
}

static int numcmp(const void *l, const void *r)
{
    const tnode_t *ta = *(const tnode_t **)l;
    const tnode_t *tb = *(const tnode_t **)r;

    return ta->count - tb->count;
}
