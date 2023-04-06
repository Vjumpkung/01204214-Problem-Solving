#include <iostream>
#include <unordered_map>

using namespace std;

const int INF = 0xfffffff;

unordered_map<int, pair<int, int>> bread_shop;

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bread_shop[a] = {b, c};
    }
    while (q--)
    {
        int where;
        cin >> where;
        int pos = -1;
        int minn = INF;
        for (int i = 0; i < 6; i++)
        {
            if (bread_shop.find(where + i) != bread_shop.end() && bread_shop[where + i].second != 0)
            {
                if (minn > bread_shop[where + i].first)
                {
                    minn = bread_shop[where + i].first;
                    pos = where + i;
                }
            }
            if (bread_shop.find(where - i) != bread_shop.end() && bread_shop[where - i].second != 0)
            {
                if (minn > bread_shop[where - i].first)
                {
                    minn = bread_shop[where - i].first;
                    pos = where - i;
                }
            }
        }
        if (pos != -1)
        {
            bread_shop[pos].second--;
            cout << minn << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}