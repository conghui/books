#include "tnode.h"


struct tnode_t *addtreex(
    struct tnode_t *p,
    char           *w,
    int             num,
    int            *found)
{
    int cond;

    if (p == NULL) {
        p = talloc(); /* make a new node */
        if ((p->word = strdup(w)) == NULL) {
            fprintf(stderr, "no enough memory\n");
            exit(EXIT_FAILURE);
        }
        p->match = *found;
        p->left = p->right = NULL;
    }
    else if ((cond = compare(w, p, num, found)) < 0) {
        p->left = addtreex(p->left, w, num, found);
    }
    else if (cond > 0) {
        p->right = addtreex(p->right, w, num, found);
    }

    return p;
}

int compare(
  char           *s,
  struct tnode_t *p,
  int             num,
  int            *found)
{
    int i;
    char *t = p->word;

    for (i = 0; *s == *t; i++, s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }

    if (i >= num) { /* identical in first num chars ? */
        *found = YES;
        p->match = YES;
    }

    return *s - *t;
}

struct tnode_t *talloc(void)
{
    return malloc(sizeof(struct tnode_t));
}

void treexprint(struct tnode_t *p)
{
    if (p != NULL) {
        treexprint(p->left);
        if (p->match) {
            printf("%s\n", p->word);
        }
        treexprint(p->right);
    }
}
