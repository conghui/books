#ifndef NLIST_H

#define NLIST_H

typedef struct nlist_t {
    struct nlist_t *next;
    char *name;
    char *defn;
} nlist_t;


unsigned hash(const char *s);
nlist_t *lookup(const char *s);
void undef(const char *s);
nlist_t *install(const char *name, const char *defn);

#endif /* end of include guard: NLIST_H */
