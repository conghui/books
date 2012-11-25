#ifndef TNODE_H

#define TNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define YES     1
#define NO      0

typedef struct tnode_t
{
    char *word;            /* points to the text */
    int match;             /* match found        */
    struct tnode_t *left;  /* left child         */
    struct tnode_t *right; /* right child        */
} tnode_t;


struct tnode_t *talloc(void);

void treexprint(struct tnode_t *p);


struct tnode_t *addtreex(
  struct tnode_t *p,
  char           *w,
  int             num,
  int            *found);

int compare(
  char           *s,
  struct tnode_t *p,
  int             num,
  int            *found);

#endif /*@@ end of include guard: TNODE_H @@*/
