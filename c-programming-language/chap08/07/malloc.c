#define MAXBYTES (unsigned)10240

void *malloc(unsigned nbytes)
{
    Header *p, *prevp;
    unsigned nunits;

    if (nbytes > MAXBYTES) {
        fprintf(stderr, "alloc: can't allocate more than %u bytes\n",
                MAXBYTES);
        return NULL;
    }

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    /* as on the book ... */
}

