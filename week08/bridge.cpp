#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> bridge;

vector<int> inp1, inp2, ans;

int main()
{
    int n;
    cin >> n;
    inp1.resize(n);
    inp2.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        inp1[a - 1] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        inp2[a - 1] = i;
    }
    for (int i = 0; i < n; i++)
    {
        bridge.push_back(make_pair(inp1[i], inp2[i]));
    }
    sort(bridge.begin(), bridge.end());
    for (int i = 0; i < n; i++)
    {
        int c = bridge[i].second;
        auto it = lower_bound(ans.begin(), ans.end(), c);
        if (it == ans.end())
        {
            ans.push_back(c);
        }
        else
        {
            *it = c;
        }
    }
    cout << ans.size() << endl;
    return 0;
}