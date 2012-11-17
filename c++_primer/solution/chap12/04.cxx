// Using the predefined function objects and function adaptors, create a
// function object to do the following:
// (a) Find all values that are greater than 1024.
// (b) Find all strings that are not equal to "pooh".
// (c) Multiply all values by 2.

#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class PrintElem {
public:
    inline void operator()(const T &elem) {
        cout << elem << " ";
    }
};

template<typename T, T _val>
class Multiplies {
public:
    //Multiplies(T val) : _val(val) {}
    inline void operator()(T &elem) {
        elem = multiplies<T>()(elem, _val);
    }

private:
    //T _val;
};

int main()
{
    int ia[] = {1000, 1024, 1045, 101, 9098};
    string sa[] = {
        string("hello"),
        string("world"),
        string("pooh"),
        string("FFFF"),
        string("AAAA")
    };

    vector<int> iv(ia, ia + 5);
    vector<string> sv(sa, sa + 5);

    typedef vector<int>::iterator iv_it_t;

    // Find all values that are greater than 1024
    for (iv_it_t ivit =
        find_if(iv.begin(), iv.end(), bind2nd(greater<int>(), 1024));
        ivit != iv.end();
        ivit = find_if(ivit + 1, iv.end(), bind2nd(greater<int>(), 1024)))
    {
        cout << *ivit << " ";
    }
    cout << endl;

    typedef vector<string>::iterator sv_it_t;
    // (b) Find all strings that are not equal to "pooh".
    for (sv_it_t svit =
            find_if(sv.begin(), sv.end(),
                not1(bind2nd(equal_to<string>(), string("pooh"))));
            svit != sv.end();
            svit = find_if(svit + 1, sv.end(),
                not1(bind2nd(equal_to<string>(), string("pooh"))))) {
        cout << *svit << " ";
    }
    cout << endl;

    // (c) Multiply all values by 2.
    for_each (iv.begin(), iv.end(), Multiplies<int, 2>());
    for_each(iv.begin(), iv.end(), PrintElem<int>());

    return 0;
}
