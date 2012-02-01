#include <iostream>
#include <list>
#include <string>

using namespace std;

static void putValue(const list<string> &strlist)
{
    cout << "( " << strlist.size() << " )\n<" << endl;
    list<string>::const_iterator cit;
    for (cit = strlist.begin(); cit != strlist.end(); ++cit)
    {
        cout << '"' << *cit << '"' << endl;
    }
    cout << ">" << endl;
}

int main()
{
    list<string> strlist;

    strlist.push_back("put function declarations in header files");
    strlist.push_back("use abstract container types instead of built-in arrays");
    strlist.push_back("declare class parameters as references");
    strlist.push_back("use reference to const types for invariant parameters");
    strlist.push_back("use less than eight parameters");

    putValue(strlist);

    return 0;
}
