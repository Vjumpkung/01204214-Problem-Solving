#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, k;
    list<int> l;
    cin >> m;
    char t;
    for (int i = 0; i < m; i++)
    {
        cin >> t >> k;
        if (t == 'I')
        {
            l.push_front(k);
        }
        else if (t == 'D' && (k >= 1 && k <= 20))
        {
            if ((int)l.size() < k)
            {
                continue;
            }
            list<int>::iterator it = l.begin();
            advance(it, k - 1);
            l.erase(it);
        }
    }
    for (auto const &i : l)
    {
        std::cout << i << "\n";
    }
    return 0;
}