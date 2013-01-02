#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "vector.h"
#include "util.h"

#define T vector_t

static void *alloc(size_t size);

T vector_init(size_t size)
{
    T vec        = alloc(sizeof * vec);
    vec->content = alloc(size * sizeof * vec->content);
    vec->size    = 0;
    vec->capacity = size;

    return vec;
}

size_t vector_size(T vec)
{
    return vec->size;
}

void vector_finalize(T vec)
{
    assert(vec != NULL);

    free(vec->content);
    free(vec);
}

static void *alloc(size_t size)
{
    void *p = malloc(size);

    if (p == NULL) {
        error("out of memory");
    }

    return p;
}

void vector_print(T vec)
{
    size_t i;

    for (i = vec->size - 10; i < vec->size; i++) {
        printf("%d ", vec->content[i]);
    }

    putchar('\n');
}
