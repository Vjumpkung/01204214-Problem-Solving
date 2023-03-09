#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1;
int a[1000];
int dp[1000];
vector<int> v[1000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    v[i].push_back(a[j]);
                }
                if (ans < dp[i])
                {
                    ans = dp[i];
                }
            }
        }
        v[i].push_back(a[i]);
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == ans)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << "\n";
            break;
        }
    }
    return 0;
}