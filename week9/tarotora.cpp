#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<int, int>, int> memo;

int tarotora(int idx, int max_diff, vector<pair<int, int>> &stage, int diff)
{
    if (diff > max_diff || diff < max_diff * -1)
    {
        return 0xfffffff;
    }
    if (idx == stage.size())
    {
        return 0;
    }
    if (memo.find({idx, diff}) != memo.end())
    {
        return memo[{idx, diff}];
    }
    int a = stage[idx].first + tarotora(idx + 1, max_diff, stage, diff + 1);
    int b = stage[idx].second + tarotora(idx + 1, max_diff, stage, diff - 1);
    memo[{idx, diff}] = min(a, b);
    return min(a, b);
}

int main()
{
    int c, n, k;
    vector<pair<int, int>> a;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            int x, y;
            cin >> x >> y;
            a.push_back({x, y});
        }
        cout << tarotora(0, k, a, 0) << endl;
        a.clear();
        memo.clear();
    }
    return 0;
}
