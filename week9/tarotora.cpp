#include <iostream>
#include <vector>

using namespace std;

int dp[100001][2];

int tarotora(int idx, int max_diff, vector<pair<int, int>> &stage, int a_count, int b_count, int total)
{
    if (abs(a_count - b_count) > max_diff)
    {
        return 0xfffffff;
    }
    if (idx == stage.size())
    {
        return total;
    }
    int a = tarotora(idx + 1, max_diff, stage, a_count + 1, b_count, total + stage[idx].first);
    int b = tarotora(idx + 1, max_diff, stage, a_count, b_count + 1, total + stage[idx].second);
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
        cout << tarotora(0, k, a, 0, 0, 0) << endl;
        a.clear();
    }
    return 0;
}
