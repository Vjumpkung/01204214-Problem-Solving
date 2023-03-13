#include <iostream>

using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p[n], w[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> w[i];
        }
        int g;
        cin >> g;
        int mw[g];
        for (int i = 0; i < g; i++)
        {
            cin >> mw[i];
        }
        int dp[1001] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 1000; j >= w[i]; j--)
            {
                if (dp[j] < dp[j - w[i]] + p[i])
                {
                    dp[j] = dp[j - w[i]] + p[i];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < g; i++)
        {
            ans += dp[mw[i]];
        }
        cout << ans << endl;
    }
    return 0;
}