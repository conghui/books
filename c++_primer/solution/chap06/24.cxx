/* Define a vector of books you'd like to read within the next virtual six 
 * months, and a set of titles that you'veread. Write a program that chooses a 
 * next book for you to read from the vector provided that you have notyet 
 * read it. When it returns the selected title to you, it should enter the 
 * title in the set of books read. If in factyou end up putting the book 
 * aside, provide support for removing the title from the set of books read. 
 * At theend of our virtual six months, print the set of books read and those 
 * books that were not read.
 */

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

static void initBooks(vector<string> &books)
{
    string b[] = {"AAAAA", "BBBBBB", "CCCCCCC", "FFFFFFFF",
                  "GGGGG", "HHHHHH", "IIIIIII", "JJJJJJJJ",
                  "KKKKK", "LLLLLL", "MMMMMMM", "NNNNNNNN"};
    books.assign(b, b + 12);
}

int main()
{
    vector<string> booksToRead;
    set<string> booksRead;
    const int month = 6;

    initBooks(booksToRead);

    for (int i = 0; i < month; ++i)
    {
        int r = rand() % booksToRead.size();
        string book = booksToRead.at(r);
        booksToRead.erase(booksToRead.begin() + r);
        cout << "choose " << book << endl;

        if (booksRead.find(book) == booksRead.end())
        {
            if (i % 4 != 0)
            {
                booksRead.insert(book);
            }
            else
            {
                cout << "putting back " << book << endl;
                booksToRead.push_back(book);
            }

        }
        else
        {
            cout << '\t' << book << " already read." << endl;
        }
    }

    return 0;
}
