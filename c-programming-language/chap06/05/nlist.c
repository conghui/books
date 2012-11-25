#include <string.>

#include "nlist.h"

#define HASHSIZE    101

static nlist_t *hashtab[HASHSIZE];  /* table of pointer */

unsigned hash(const char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + hashval * 31;
    }

    return hashval;
}

nlist_t *lookup(const char *s)
{
    nlist_t *p;
    unsigned hashval;

    hashval = hash(s);

    for (p = hashtab[hashval]; p != NULL; p = p->next) {
        if (strcmp(s, p->name) == 0) {
            return p;
        }
    }

    return NULL;
}

void undef(const char *s) {
    unsigned hashval;
    nlist_t *cur;
    nlist_t *prev;

    hashval = hash(s);
    for (prev = NULL; cur = hashtab[hashval]; cur != NULL; 
            prev = cur; cur = cur->next) {
        if (strcmp(s, cur->name) == 0) {
            break;
        }
    }

    if (cur == NULL) { /* name not found */
        return ;
    }

    /* find the name */

    if (prev == NULL) { /* cur is the first item */
        hashtab[hashval] = cur->next;
    }
    else {
        prev->next = cur->next;
        free(cur->name);
        free(cur->defn);
        free(cur);
    }
    
}
