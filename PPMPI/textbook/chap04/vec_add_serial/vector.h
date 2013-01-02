#ifndef VECTOR_H

#define VECTOR_H

typedef int Item;

#define T vector_t

typedef struct T *T;

struct T {
    Item *content;
    size_t size;
    size_t capacity;
};

T vector_init(size_t size);
size_t vector_size(T vec);
void vector_finalize(T vec);
void vector_print(T vec);

#undef T

#endif /* end of include guard: VECTOR_H */
