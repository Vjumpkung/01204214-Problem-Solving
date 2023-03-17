#include <iostream>
#include <list>

using namespace std;

list<int> la[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, x, s;
    char c;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> x >> s;
        if (c == 'N')
        {
            la[s].push_back(x);
        }
        else if (c == 'M')
        {
            la[s].splice(la[s].end(), la[x]);
        }
    }
    for (int i = 0; i < 100001; i++)
    {
        if (la[i].size() != 0)
        {
            for (auto j : la[i])
            {
                cout << j << "\n";
            }
        }
    }
    return 0;
}