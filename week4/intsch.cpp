#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n, c = 1;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int startx, end;
        cin >> startx >> end;
        v.push_back({startx, end});
    }
    sort(v.begin(), v.end(), sortbysec);
    vector<pair<int, int>>::iterator it = v.begin();
    pair<int, int> e = v.front();
    it++;
    while (it != v.end())
    {
        if ((*it).first < e.second)
        {
            it++;
        }
        else
        {
            c++;
            e = *it;
        }
    }
    cout << c << endl;
    return 0;
}