#include <ctype.h>
#include "tnode.h"
#include "getword.h"

#define MAXWORD 100

int main(void)
{
    tnode_t *root;
    char word[MAXWORD];
    int linenum = 1;

    root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(*word) && noiseword(word) == -1) {
            root = addtreex(root, word, linenum);
        }
        else if (word[0] == '\n') {
            linenum++;
        }
    }

    treexprint(root);

    return 0;
}
