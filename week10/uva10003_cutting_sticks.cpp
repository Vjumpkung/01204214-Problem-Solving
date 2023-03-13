#include <iostream>

using namespace std;

int l;
int n[51];
int dp[51][51];

int solve(int l, int r)
{
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    if (l + 1 == r)
    {
        return dp[l][r] = 0;
    }
    int min = 1000000000;
    for (int k = l + 1; k < r; k++)
    {
        int t = solve(l, k) + solve(k, r) + n[r] - n[l];
        if (t < min)
        {
            min = t;
        }
    }
    dp[l][r] = min;
    return min;
}

int main()
{
    while (1)
    {
        cin >> l;
        if (l == 0)
        {
            break;
        }
        for (int i = 0; i < 51; i++)
        {
            for (int j = 0; j < 51; j++)
            {
                dp[i][j] = -1;
            }
        }
        int m;
        cin >> m;
        n[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> n[i];
        }
        n[m + 1] = l;
        printf("The minimum cutting is %d.\n", solve(0, m + 1));
    }
    return 0;
}