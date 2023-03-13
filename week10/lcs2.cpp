#include <iostream>
#include <vector>

using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

int dp[201][201];

int main()
{
    fastio;
    string s, t;
    vector<char> ans;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i > 0 and j > 0 and s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else if (i > 0 and j > 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << dp[n][m] << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}