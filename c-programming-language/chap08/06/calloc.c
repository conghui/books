void *calloc(unsigned n, unsigned size)
{
    unsigned i, nb;
    char *p, *q;

    nb = size * n;

    if ((p = q = malloc(nv)) != NULL) {
        for (i = 0; i < nb; i++)
            *p++ = 0;
    }

    return q;
}
