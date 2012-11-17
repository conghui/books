/* Write a program that, given the string
 *  "/.+(STL).*$1/"
 * erases all the characters except STL first using erase(pos,count) and then 
 * using erase(iter,iter) .
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string origin_line = "/.+(STL).*$1/";
    const string STL = "STL";
    string::size_type pos;

    /* using erase(pos, count) */
    string copy_line1 = origin_line;
    for (pos = copy_line1.find_first_not_of(STL);
         pos != string::npos;
         pos = copy_line1.find_first_not_of(STL, pos))
    {
        copy_line1.erase(pos,1);
    }
    cout << "The remaining string is: " << copy_line1 << endl;
    cout << endl;

    /* using erase(iter, iter) */
    string copy_line2 = origin_line;
    for (string::iterator it = copy_line2.begin();
         it != copy_line2.end();)
    {
        if (STL.find(*it) == string::npos)
        {
            copy_line2.erase(it);
        }
        else
        {
            ++it;
        }
    }
    cout << "The remaining string is: " << copy_line2 << endl;
    return 0;
}
