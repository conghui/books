/* Add an exclusion set for recognizing words in which the trailing 's' should 
 * not be removed but for whichthere exists no general rule. For example, 
 * three words to place in this set are the proper names Pythagoras,Brahms, 
 * and Burne_Jones. Fold the use of this exclusion set into the suffix_s() 
 * function of Section 6.10.
 */
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

static void suffix_s(vector<string> *words, const set<string> &exclusionSet)
{
    vector<string>::iterator it;

    for (it = words->begin(); it != words->end(); ++it)
    {
        if (exclusionSet.find(*it) != exclusionSet.end())
        {
            cout << *it << " is in the exclusion set." << endl;
        }
    }

    /* the jobs that suffix_s should do go on here */
}
