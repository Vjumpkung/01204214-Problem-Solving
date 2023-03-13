#include <iostream>

using namespace std;

int coins[] = {1, 5, 10, 25, 50};
int dp[7490] = {0};

void coin_change()
{
    dp[0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = coins[i]; j < 7490; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
}

int main()
{
    int n;
    coin_change();
    while (cin >> n)
    {
        cout << dp[n] << "\n";
    }
    return 0;
}