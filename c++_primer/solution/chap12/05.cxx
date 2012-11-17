// Define a function object to evaluate three objects and return the middle
// value. Define a function to do the same operation. Show examples of using
// each object directly and by passing each to a function. Compare and
// contrast the behavior of each.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<typename Iterator>
class Middle
{
public:
    Middle(Iterator first, Iterator last) :
        _first(first), _last(last) { };
    Iterator operator()() {
        std::sort(_first, _last);
        Iterator mid = _first + (_last - _first) / 2;
        return mid;
    }
private:
    Iterator _first;
    Iterator _last;
};

int main(void)
{
    int ia[] = {20, 10, 30};
    string sa[] = {"AAA", "FFF", "CCC", "DDD", "BBB"};
    vector<int> iv(ia, ia + 3);
    vector<string> sv(sa, sa + 5);

    cout << "The result should be 20: "
         << *Middle<int *>(ia, ia + 3)()
         << endl;

    cout << "The result should be 20 using vector's iteraotr: "
         << *Middle<vector<int>::iterator>(iv.begin(), iv.end())() 
         << endl;

    cout << "the result should be CCC in array: "
         << *Middle<string *>(sa, sa + 5)()
         << endl;

    cout << "The result should be CCC in vector: "
         << *Middle<vector<string>::iterator>(sv.begin(), sv.end())()
         << endl;


    return 0;
}
