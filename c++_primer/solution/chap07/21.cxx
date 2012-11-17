/* Section 7.5 defines the function factorial(). Define a pointer to a 
 * function that can point to factorial().Invoke the function through this 
 * pointer to generate the factorial of number 11. 
 */
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
    unsigned long (*pf)(int);
    pf = factorial;
    
    cout << pf(11) << endl;

    return 0;
}
