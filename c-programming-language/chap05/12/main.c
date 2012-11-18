#include "esettab.h"
#include "entab.h"


int main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    esettab(argc, argv, tab);
    entab(tab);

    return 0;
}
