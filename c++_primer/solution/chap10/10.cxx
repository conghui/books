/* Define a function template count() to count the number of occurrences of some value in an array. Write a program to call it. Pass it in turn an array of 
double s, ints, and chars. Introduce a specialized template instance of the 
count() function to handle strings. Rerun the program you wrote to call the 
function template instantiations.
*/

#include <iostream>
#include <string>
using std::string;

template<typename T>
size_t count(T *arr, size_t size, T elem) {
    size_t times = 0;

    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == elem)
            times++;
    }

    return times;
}

template<> size_t count<string>(string *A, size_t size, string E) {
    std::cout << "This is explicit specialization" << std::endl;
    size_t times = 0;

    for (size_t i = 0; i < size; i++) {
        if (A[i].compare(E) == 0)
            times++;
    }

    return times;
}

int main()
{
    using std::cout;
    using std::endl;

    double darr[5] = {1.1, 2.2, 2.2, 3.3, 2.2};
    char   carr[5] = {'a', 'a', 'b', 'c', 'c'};
    int    iarr[5] = {1, 2, 3, 4, 2};
    string sarr[5] = {"AA", "BB", "AA", "CC", "a"};

    cout << count(darr, 5, 2.2) << endl;
    cout << count(carr, 5, 'a') << endl;
    cout << count(iarr, 5, 2) << endl;
    cout << count(sarr, 5, string("AA")) << endl;

    return 0;
}
