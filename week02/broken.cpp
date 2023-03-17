#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    string s;
    list<char> t;
    list<char>::iterator it;
    bool f = false;
    while (getline(cin, s))
    {
        for (unsigned int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
            {
                it = t.begin();
                f = true;
                continue;
            }
            else if (s[i] == ']')
            {
                it = t.end();
                f = true;
                continue;
            }
            if (f)
            {
                t.insert(it, s[i]);
            }
            else
            {
                t.push_back(s[i]);
            }
        }
        for (auto const i : t)
        {
            cout << i;
        }
        t.clear();
        f = false;
        cout << endl;
    }
    return 0;
}