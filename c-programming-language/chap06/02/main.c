#include <stdlib.h>
#include <string.h>
#include "tnode.h"
#include "getword.h"

int main(int argc, char **argv)
{
    struct tnode_t *root;
    char word[MAXWORD];
    size_t  num;        /* # of the first ident. chars */
    int  found = NO; /* YES of match if found       */

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) > num) {
            root = addtreex(root, word, num, &found);
        }
        found = NO;
    }

    treexprint(root);

    return 0;
}
