/* Write a program that, given the string
 *      "ab2c3d7R4E6"
 * finds each numeric character and then each alphabet character first using 
 * find_first_of() and then find_first_not_of().
 */

#include <iostream>
#include <string>

using namespace std;


int main()
{
    const string givenStr = "ab2c3d7R4E6";
    const string numeric = "0123456789";
    const string alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string::size_type pos = 0;

    /* find out the numeric using find_first_of */
    cout << "The numeric characters found by find_first_of are: ";
    for (pos = givenStr.find_first_of(numeric); 
         pos != string::npos; 
         ++pos, pos = givenStr.find_first_of(numeric, pos))
    {
        cout << givenStr.at(pos) << ' ';
    }
    cout << endl;

    /* find out the alphabet character using find_first_of */
    cout << "The alpahbet characters found by find_first_of are: ";
    for (pos = givenStr.find_first_of(alphabet);
         pos != string::npos;
         ++pos, pos = givenStr.find_first_of(alphabet, pos))
    {
        cout << givenStr.at(pos) << ' ';
    }
    cout << endl << endl;

    /* find out the numeric characters using find_first_not_of */
    cout << "The numeric characters found by find_first_not_of are: ";
    for (pos = givenStr.find_first_not_of(alphabet);
         pos != string::npos;
         ++pos, pos = givenStr.find_first_not_of(alphabet, pos))
    {
        cout << givenStr.at(pos) << ' ';
    }
    cout << endl;

    /* find out the alphabet characters using find_first_not_of */
    cout << "The alphabet chracters found by find_first_not_of are: ";
    for (pos = givenStr.find_first_not_of(numeric);
         pos != string::npos;
         pos++, pos = givenStr.find_first_not_of(numeric, pos))
    {
        cout << givenStr.at(pos) << ' ';
    }
    cout << endl;

    return 0;
}
