#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int d, n;
    set<int> s;
    vector<pair<int, int>> bridge;
    vector<int> v;
    int maxx = -1;
    cin >> d >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        bridge.push_back({a, b});
        s.insert(a);
        s.insert(b);
    }
    for (auto i = s.begin(); i != s.end(); i++)
    {
        v.push_back(*i);
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        float x = (v[i] + v[i + 1]) / (2.0);
        int count = 0;
        for (int j = 0; j < bridge.size(); j++)
        {
            if (x >= bridge.at(j).first and x <= bridge.at(j).second)
            {
                count++;
            }
        }
        if (count > maxx)
        {
            maxx = count;
        }
    }
    cout << maxx;
    return 0;
}