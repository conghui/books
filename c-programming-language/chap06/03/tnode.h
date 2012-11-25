#ifndef TNODE_H

#define TNODE_H


typedef struct linklist_t { /* linked list of line numbers */
    int                lnum;
    struct linklist_t *ptr;
} linklist_t;

typedef struct tnode_t { /*  the tree node */
    char           *word;    /* points to the text */
    linklist_t     *lines;   /* line numbers       */
    struct tnode_t *left;    /* left child         */
    struct tnode_t *right;   /* right child        */
} tnode_t;

int noiseword(const char *w);
linklist_t *lalloc(void);
void treexprint(tnode_t *p);
void addln(tnode_t *p, int linenum);
tnode_t *addtreex(tnode_t *p, char *w, int linenum);
tnode_t *talloc(void);
#endif /* end of include guard: TNODE_H */
