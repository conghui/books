/*
Write a program that defines an IntArray object (where IntArray is the class 
type defined in Section 2.3) and performs the following actions. We have three 
files containing integer values.
1.  Read the first file and assign the first, third, fifth, ..., nth value 
    read (where n is an odd number) to the IntArray object; then display the 
    content of the IntArray object.
2.  Read the second file and assign the fifth, tenth, ..., nth value read 
    (where n is a multiple of 5) to the IntArray object; then display the 
    content of the IntArray object.
3.  Read the third file and assign the second, fourth, sixth..., nth value 
    read (where n is an even number) to the IntArray object; then display the 
    content of the Int- Array object.
Use the IntArray operator[]() defined in Exercise 11.2 to store values into 
and read values from the IntArray object. Because operator[]() may throw an 
exception, use one or more try blocks and catch clauses in your program to 
handle the possible exceptions thrown by operator[](). Explain the reasoning 
behind where you located the try blocks in your program.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "IntArray.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "usage: " << argv[0] << " <file1> <file2> <file3>\n";
        exit(EXIT_FAILURE);
    }

    IntArray ia(10);
    int ix;
    int cnt;
    int val;
    ifstream infile;

    for (int i = 1; i <= 3; +=i++) {
        infile.open(argv[i], ios::in);
        if (!infile) {
            cerr << "Eror: unable to open " << argv[i] << " for input\n";
            exit(EXIT_FAILURE);
        }
        cout << "Reading values from " << argv[i] << endl;

        try {
            ix = cnt = 0;
            while (infile >> val) {
                switch (i) {
                    case 1:
                        if (++cnt % 2) {
                            ia[ix] = val;
                        }
                        break;
                    case 2:
                        if (++cnt % 5 == 0) {
                            ia[ix] = val;
                        }
                        break;
                    case 3:
                        if (++cnt % 2 == 0) {
                            ia[ix] = val;
                        }
                        break;
                }
                ix++;
            }
        }
        catch (OutOfBounds o) {
            cerr << "Attempted to assign value outside of array bounds. "
                 << "Skipping remainer of file.\n";
        }

        infile.close();
        
        cout << ix << "value assigned." << endl;
        for (int j = 0; j < ix; j++) {
            cout << ia[j] << endl;
        }
        cout << endl;
    }

    return 0;
}
