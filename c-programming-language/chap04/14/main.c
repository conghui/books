#include <stdio.h>

#define swap(t, x, y) { \
    t _z;   \
    _z = x; \
    x = y;  \
    y = _z; \
}

int main(void) {
    int a = 1;
    int b = 2;

    printf("a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("after swap, a = %d, b = %d\n", a, b);

    return 0;
}
