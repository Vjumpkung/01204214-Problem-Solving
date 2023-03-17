#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l;
    int m, s, u;
    cin >> m;
    string t;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        if (t == "li")
        {
            cin >> s;
            l.push_front(s);
        }
        else if (t == "ri")
        {
            cin >> s;
            l.push_back(s);
        }
        else if (t == "lr")
        {
            if (l.size() > 0)
            {
                u = l.front();
                l.pop_front();
                l.push_back(u);
            }
        }
        else if (t == "rr")
        {
            if (l.size() > 0)
            {
                u = l.back();
                l.pop_back();
                l.push_front(u);
            }
        }
    }
    for (auto const &i : l)
    {
        cout << i << "\n";
    }
    return 0;
}