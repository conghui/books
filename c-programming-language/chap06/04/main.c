#include "tnode.h"
#include "getword.h"

#define MAXWORD 100

int main(void)
{
    tnode_t *root;
    char word[MAXWORD];
    int i;

    root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    treestore(root);
    sortlist();

    for (i = 0; i < ntn; i++) {
        printf("%2d: %20s\n", list[i]->count, list[i]->word);
    }

    return 0;
}
