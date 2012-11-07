#include <stdio.h>

int main(void)
{
    return 0;
}

static int setbits(int x, int p, int n, int y)
{
    return  (x & ~(~(~0 << n)) << (p - n + 1)) | 
            (y & (~(~0 << n)) << (p - n + 1));
}
