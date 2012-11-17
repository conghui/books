/* Our program does not handle suffixes ending in ed, as in surprised;     ly, 
 * as in surprisingly; and ing ,as in surprising . Add one of the following 
 * suffix handlers to the program: (a) suffix_ed(), (b)suffix_ly(), or (c) 
 * suffix_ing().
 */

#include <iostream>
#include <string>

using namespace std;

static string suffix_ed(string &word)
{
    string ed("ed");
    string::size_type pos = word.length() - 2;

    if (word.compare(pos, 2, ed) == 0)
    {
        /* erase the suffix ed */
        word.erase(pos, string::npos);
    }

    return word;
}

static string suffix_ing(string &word)
{
    string ing("ing");
    string::size_type pos = word.length() - 3;

    if (word.compare(pos, 3, ing) == 0)
    {
        /* erase ing */
        word.erase(pos, string::npos);
    }

    return word;
}

static string suffix_ly(string &word)
{
    string ly("ly");
    string::size_type pos = word.length() - 2;

    if (word.compare(pos, 2, ly) == 0)
    {
        /* erase ly */
        word.erase(pos, string::npos);
    }

    return word;
}

int main()
{
    string stred("worked");
    string strly("nicely");
    string str_ing("working");

    suffix_ed(stred);
    suffix_ing(str_ing);
    suffix_ly(strly);
    cout << stred << endl;
    cout << strly << endl;
    cout << str_ing << endl;

    return 0;
}
