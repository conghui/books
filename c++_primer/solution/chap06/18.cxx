/* Write a program that accepts the following two strings:
 *  string quote1( "When lilacs last in the dooryard bloom'd" );
 *  string quote2( "The child is father of the man" );
 * Using the assign() and append() operations, create the 
 * stringstring 
 *  sentence( "The child is in the dooryard" );
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string quote1( "When lilacs last in the dooryard bloom'd" ); 
    string quote2( "The child is father of the man" );           
    string sentence;

    string::size_type pos = quote2.find("father");
    sentence.assign(quote2, 0, pos - 1);

    string::size_type pos1 = quote1.find("in");
    string::size_type pos2 = quote1.find("bloom");
    sentence.append(quote1.begin() + pos1, quote1.begin() + pos2 - 1);

    cout << sentence << endl;
    return 0;
}
