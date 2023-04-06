#include <iostream>

using namespace std;

const int MAX_N = 1200, MAX_K = 20;
int dp[MAX_N][MAX_K];
int prime[MAX_N];
int n, k;
bool not_prime[MAX_N];

int main()
{
    int i, j, k, t = 0;
    for (i = 2; i < MAX_N; i++)
    {
        if (!not_prime[i])
        {
            prime[t++] = i;
        }
        for (j = 0; j < t && prime[j] * i < MAX_N; j++)
        {
            not_prime[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    dp[0][0] = 1;
    for (i = 0; i < t; i++)
    {
        for (j = 14; j >= 1; j--)
        {
            for (k = 1120; k >= prime[i]; k--)
            {
                dp[k][j] += dp[k - prime[i]][j - 1];
            }
        }
    }
    while (1)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
        {
            break;
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}
