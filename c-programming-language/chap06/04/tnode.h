#ifndef TNODE_H

#define TNODE_H

typedef struct tnode_t {/* the tree node */
    char           *word;    /* points to the text */
    int             count;   /* # of occurrences   */
    struct tnode_t *left;    /* left child         */
    struct tnode_t *right;   /* right child        */
} tnode_t;


extern tnode_t *list[];
extern int      ntn;

tnode_t *addtree(tnode_t *p, char *w);
tnode_t *talloc(void);
void treestore(tnode_t *p);
void sortlist(void);
#endif /* end of include guard: TNODE_H */
