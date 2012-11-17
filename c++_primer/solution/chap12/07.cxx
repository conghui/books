//Write a program to read a sequence of integer numbers from standard input
//using an istream_iterator. Write the odd numbers into one file using an
//ostream_iterator. Each value should be separated by a space. Write the even
//numbers into a second file also using an ostream_iterator. Each of these
//values should be placed on a separate line.

#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    istream_iterator<int> input(cin);
    istream_iterator<int> oes;
    vector<int> iv;

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <file1> <file2>\n";
        exit(EXIT_FAILURE);
    }

    // read integer from cin
    copy(input, oes, back_inserter(iv));

    ofstream outfile1(argv[1]);
    ofstream outfile2(argv[2]);

    if (!(outfile1 && outfile2)) {
        cerr << "can not open file\n";
        exit(EXIT_FAILURE);
    }

    ostream_iterator<int> out1(outfile1);
    ostream_iterator<int> out2(outfile2);

    vector<int>::iterator it = iv.begin();
    for (; (it = find_if(it, iv.end(), bind2nd(modulus<int>(), 2))) !=
            iv.end(); ++it) {
        copy(it, it + 1, out1);
    }

    it = iv.begin();
    for (; (it = find_if(it, iv.end(), not1(bind2nd(modulus<int>(), 2)))) !=
            iv.end(); ++it) {
        copy(it, it + 1, out2);
    }

    outfile1.close();
    outfile2.close();
    return 0;
}
