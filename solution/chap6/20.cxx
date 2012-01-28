/* Define a map for which the index is the family surname and the key is a 
 * vector of the children's names.Populate the map with at least six entries. 
 * Test it by supporting user queries based on a surname, adding achild to one 
 * family and triplets to another, and printing out all the map entries.
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> children;
typedef string surname;

static void insert(map<surname, children> &family)
{
    typedef map<surname, children>::value_type valType;
    string a[] = {"a1", "a2", "a3", "a4"};
    string b[] = {"b1", "b2", "b3"};
    string c[] = {"c1", "c2"};
    string d[] = {"d1"};
    vector<string> va(a, a + 4);
    vector<string> vb(b, b + 3);
    vector<string> vc(c, c + 2);
    vector<string> vd(d, d + 1);

    family.insert(valType("a", va));
    family.insert(valType("b", vb));
    family.insert(valType("c", vc));
    family.insert(valType("d", vd));
}

static void print(const map<surname, children> &family)
{
    map<surname, children>::const_iterator mit = family.begin();
    
    for (; mit != family.end(); ++mit)
    {
        cout << mit->first << ":" << endl;
        children::const_iterator cit;
        for (cit = mit->second.begin(); cit != mit->second.end(); ++cit)
        {
            cout << '\t' << mit->first << " " << *cit << endl;
        }
        cout << endl;
    }
}

static void query(const map<surname, children> &family, const string &name)
{
    if (name.empty())
        return ;

    map<surname, children>::const_iterator mit = family.find(name);

    if (mit == family.end())
    {
        cout << "family " << name << " doesn't exist." << endl;
    }
    else
    {
        children::const_iterator cit;
        cout << "The members of family " << name << " is:" << endl;
        for (cit = mit->second.begin(); cit != mit->second.end(); ++cit)
        {
            cout << '\t' << mit->first << " " << *cit << endl;
        }
    }
}

int main()
{
    map<surname, children> family;
    insert(family);   
    print(family);
    query(family, "a");
    return 0;
}
