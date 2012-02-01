/* Let's go back to the sort() example. Provide the definition for the 
 * function
 *  int sizeCompare( const string &, const string & );
 * so that if the two parameters refer to strings of the same size, then 
 * sizeCompare() returns 0; otherwise,if the string represented by the 
 * first parameter is shorter than the string represented by the 
 * secondparameter, a negative number is returned; if it is greater, a 
 * positive number is returned. Remember that thestring operation size() 
 * yields the size of a string.  Change main() to call  sort() with a 
 * third argumentthat is a pointer to  sizeCompare().
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static bool sizeCompare(const string &str1, const string &str2)
{
    if (str1.size() < str2.size())
        return true;
    return false;
}

int main()
{
    string strs[4] = {"aaa", "b", "ff", "dd" };

    sort(strs, strs + 4, sizeCompare);

    for (int i = 0; i < 4; i++)
    {
        cout << strs[i] << endl;
    }

    return 0;
}
