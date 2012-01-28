/* Write a program that accepts these definitions:
    string sentence( "kind of" );
    string s1( "whistle" );
    string s2( "pixie" );
Using the various insert string functions, provide sentence with the value
    "A whistling-dixie kind of walk."
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string sentence( "kind of" );
    string s1( "whistle" );
    string s2( "pixie" );
    
    s1.insert(0, "A ");
    s1.erase(s1.end() - 1);
    s1.insert(s1.length(), "ing-d");

    string::iterator it = find(s2.begin(), s2.end(), 'i');
    s1.insert(s1.end(), it, s2.end());
    s1.insert(s1.end(), ' ');
    s1.insert(s1.length(), "walk.");
    cout << s1 << endl;
    return 0;
}
