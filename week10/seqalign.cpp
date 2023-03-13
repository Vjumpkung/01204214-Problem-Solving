#include <iostream>

using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < m + 1; i++)
    {
        dp[0][i] = i;
    }
    for (int j = 0; j < n + 1; j++)
    {
        dp[j][0] = j;
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i > 0 and j > 0 and word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (i > 0 and j > 0)
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    return dp[n][m];
}

int main()
{
    fastio;
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}
