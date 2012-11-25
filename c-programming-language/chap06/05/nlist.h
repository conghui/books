#ifndef NLIST_H

#define NLIST_H

typedef struct nlist_t {
    struct nlist_t *next;
    char *name;
    char *defn;
} nlist_t;


#endif /* end of include guard: NLIST_H */
