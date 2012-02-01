/* Write a program that, given the strings
string generic1( "Dear Ms Daisy:" );
string generic2( "MrsMsMissPeople" );
implements the function
string generate_salutation( string generic1,
                            string lastname,
                            string generic2,
                            string::size_type pos,
                            int length );
using the replace() operations, where lastname replaces Daisy and pos indexes into generic2 of
length characters replacing Ms. For example, the following
string lastName( "AnnaP" );
string greetings =
        generate_salutation( generic1, lastName, generic2, 5, 4 );
returns the string
    Dear Miss AnnaP:
 */
#include <iostream>
#include <string>

using namespace std;

static string generate_salutation(string generic1,
                                  string lastname,
                                  string generic2,
                                  string::size_type pos,
                                  int length)
{
    string Daisy("Daisy");
    string Ms("Ms");
    string::size_type dpos = generic1.find(Daisy);
    string::size_type mpos = generic1.find(Ms);
    generic1.replace(dpos, Daisy.length(), lastname);
    generic1.replace(mpos, Ms.length(), generic2, pos, length);

    return generic1;
}

int main()
{
    string generic1( "Dear Ms Daisy:" );
    string generic2( "MrsMsMissPeople" );
    string lastName( "AnnaP" );
    string greetings =
            generate_salutation( generic1, lastName, generic2, 5, 4 );
    cout << greetings << endl;
    return 0;
}
