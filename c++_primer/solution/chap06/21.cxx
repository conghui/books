/* Extend the map of Exercise 6.20 by having the vector store a pair of 
 * strings: the child's name and birthday.Revise the Exercise 6.20 
 * implementation to support the new pair vector. Test your modified test 
 * program toverify its correctness. 
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

typedef pair<string, string> profile;
typedef vector<profile> children;
typedef string surname;

static void insert(map<surname, children> &family)
{
    typedef map<surname, children>::value_type valType;
    string a[] = {"a1", "a2", "a3", "a4"};
    string ba[] = {"1990-1", "1990-2", "1990-3", "1990-4"};
    string b[] = {"b1", "b2", "b3"};
    string bb[] = {"1991-1", "1991-2", "1991-3"};
    string c[] = {"c1", "c2"};
    string bc[] = {"1992-1", "1992-2"};
    string d[] = {"d1"};
    string bd[] = {"1993-1"};

    profile pa[4];
    profile pb[3];
    profile pc[2];
    profile pd[1];

    for (int i = 0; i < 4; ++i)
    {
        pa[i] = make_pair(a[i], ba[i]);
    }

    for (int i = 0; i < 3; ++i)
    {
        pb[i] = make_pair(b[i], bb[i]);
    }

    for (int i = 0; i < 2; ++i)
    {
        pc[i] = make_pair(c[i], bc[i]);
    }

    for (int i = 0; i < 1; ++i)
    {
        pd[i] = make_pair(d[i], bd[i]);
    }

    children va(pa, pa + 4);
    children vb(pb, pb + 3);
    children vc(pc, pc + 2);
    children vd(pd, pd + 1);

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
            cout << '\t' << mit->first << " " << cit->first << " " << cit->second << endl;
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
            cout << '\t' << mit->first << " " << cit->first << " " << cit->second << endl;
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
