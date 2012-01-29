/* Rewrite factorial() as an iterative function. */
#include <iostream>
using namespace std;

static unsigned long factorial(int n)
{
    if (n <= 1)
        return 1;

    unsigned long *arr = new unsigned long[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    unsigned long ret = arr[n];

    delete [] arr;

    return ret;
}

int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        cout << factorial(i) << (i == 10 ? '\n' : ' ');
    }


    return 0;
}
