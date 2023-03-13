#include <iostream>

using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

int dp[201][201];
string s;

int rna(int i, int j)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (j <= i + 4)
    {
        dp[i][j] = 0;
        return dp[i][j];
    }
    int a = rna(i, j - 1);
    for (int k = i; k <= j; k++)
    {
        if (k < j - 4)
        {
            if ((s[k] == 'A' and s[j] == 'U') or (s[k] == 'U' and s[j] == 'A'))
            {
                a = max(a, rna(i, k - 1) + rna(k + 1, j - 1) + 1);
            }
            else if ((s[k] == 'C' and s[j] == 'G') or (s[k] == 'G' and s[j] == 'C'))
            {
                a = max(a, rna(i, k - 1) + rna(k + 1, j - 1) + 1);
            }
        }
    }
    dp[i][j] = a;
    return dp[i][j];
}

int main()
{
    fastio;
    cin >> s;
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << rna(0, s.length() - 1) << "\n";
    return 0;
}