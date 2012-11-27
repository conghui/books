/* Write a program that, given the string
 *     string line1 = "We were her pride of 10 she named us --";
 *     string line2 = "Benjamin, Phoenix, the Prodigal"
 *     string line3 = "and perspicacious pacific Suzanne";
 *     string sentence = line1 + ' ' + line2 + ' ' + line3;
 * counts the number of words in the sentence and identifies the largest and 
 * smallest words. If more than one word is either the largest or smallest, 
 * keep track of all of them.
 */

/* To find the word, we can use the following method
 * - find position of the first character of alphabet character
 * - find position of the first character of non-alphabet character 
 * - get the substring and push it back into a vector
 * - sort the vector based on the length of each element 
 * - print the numer of words and the largest and the smallest words
 */

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

static vector<string> *separateWord(const string &sentence);
static void print(const vector<string> &words);
static bool compareLength(string a, string b);

int main()
{
    string line1 = "We were her pride of 10 she named us --"; 
    string line2 = "Benjamin, Phoenix, the Prodigal";
    string line3 = "and perspicacious pacific Suzanne";       
    string sentence = line1 + ' ' + line2 + ' ' + line3;      
    vector<string> *words;
    
    words = separateWord(sentence);
    /* sort the words based on the length of each element */
    sort(words->begin(), words->end(), compareLength);
    print(*words);
    return 0;
}

static vector<string> *separateWord(const string &sentence)
{
    string::size_type pos = 0, prev_pos = 0;
    const string alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    vector<string> *words = new vector<string>();

    prev_pos = sentence.find_first_of(alphabet);
    pos = sentence.find_first_not_of(alphabet);
    for (; prev_pos != string::npos && pos != string::npos;)
    {
        words->push_back(sentence.substr(prev_pos, pos - prev_pos));
        ++pos;
        prev_pos = sentence.find_first_of(alphabet, pos);
        pos = sentence.find_first_not_of(alphabet, prev_pos);
    }

    words->push_back(sentence.substr(prev_pos, pos - prev_pos));

    return words;
}

static void print(const vector<string> &words)
{
    vector<string>::const_iterator c_it, c_prev_it;
    vector<string>::const_iterator c_smallest_it = words.begin();
    vector<string> smallest, largest;

    int count = 1;

    c_prev_it = words.begin();
    c_it = c_prev_it + 1;
    smallest.push_back(*c_prev_it);
    for (; c_it != words.end(); ++c_it)
    {
        if (c_it->length() == c_smallest_it->length())
        {
            smallest.push_back(*c_it);
        }
        if (*c_it != *c_prev_it)
        {
            cout << *c_prev_it << " " << count << endl;
            c_prev_it = c_it;
            count = 1;       
        }
        else
        {
            count++;
        }
    }

    /* If the last word didn't print */
    if (c_prev_it != words.end() - 1)
    {
        cout << *c_prev_it << " " << count << endl;
    }

    cout << "The smallest word is: ";
    for (vector<string>::iterator it = smallest.begin();
         it != smallest.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "The largest word is:  " << *(words.end() - 1) << endl;
}

static bool compareLength(string a, string b)
{
    return a.length() < b.length();
}
