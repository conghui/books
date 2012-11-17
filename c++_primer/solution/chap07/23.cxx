#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double (*mfunc[3])(double) = {sin, cos, sqrt};

    cout << mfunc[2](97.9) << endl;

    return 0;
}
