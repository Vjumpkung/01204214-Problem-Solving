#include <iostream>

using namespace std;

int n;
int p[100001][3];
int dp[100001][3];

/*
mode 0 = any
mode 1 = coffee
mode 2 = bakery
*/

int star(int idx, int mode)
{
    if (dp[idx][mode] != -1)
    {
        return dp[idx][mode];
    }
    if (idx >= n)
    {
        return 0;
    }
    else
    {
        if (mode == 0)
        {
            dp[idx][mode] = max(star(idx + 1, 0), max(star(idx + 1, 1), star(idx + 1, 2)));
            return dp[idx][mode];
        }
        else if (mode == 1)
        {
            dp[idx][mode] = p[idx][1] + max(star(idx + 1, 2), star(idx + 1, 0));
            return dp[idx][mode];
        }
        else
        {
            dp[idx][mode] = p[idx][2] + max(star(idx + 1, 1), star(idx + 1, 0));
            return dp[idx][mode];
        }
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i][1] >> p[i][2];
        dp[i][0] = -1;
        dp[i][1] = -1;
        dp[i][2] = -1;
    }
    int ans1 = max(star(0, 0), max(star(0, 1), star(0, 2)));
    if (ans1 < 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    cout << ans1 << "\n";
    return 0;
}
