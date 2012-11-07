#include <stdio.h>

int main(void)
{
    return 0;
}

static int calmid(int a, int b)
{
    return (a + b) / 2;
}
static int binsearch(int x, int *v, int n)
{
    int low;
    int high;
    int mid;

    low = 0;
    high = n - 1;
    mid = calmid(low, high);

    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

        mid = calmid(low, high);
    }

    if (x == v[mid]) {
        return mid;
    }
    else {
        return -1;
    }
}
