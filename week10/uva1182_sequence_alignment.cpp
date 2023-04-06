#include <iostream>
#define INT_MIN -999999999

using namespace std;

string s1;
string s2;
int sl1, sl2;
int dp[51][51][2];

int solve(int a, int b, int f)
{
    if (a == sl1 and b == sl2)
    {
        return 0;
    }
    if (a == sl1 or b == sl2)
    {
        return -1;
    }
    int &ret = dp[a][b][f];
    if (ret != -1)
    {
        return ret;
    }
    ret = INT_MIN;
    ret = max(ret, solve(a + 1, b + 1, 1));
    if (s1[a] == s2[b])
    {
        ret += 2;
    }
    ret = max(ret, -f + solve(a + 1, b, 0));
    ret = max(ret, -f + solve(a, b + 1, 0));
    return ret;
}

int main()
{
    int r;
    cin >> r;
    while (r--)
    {
        cin >> s1 >> s2;
        sl1 = s1.length();
        sl2 = s2.length();
        for (int i = 0; i < 51; i++)
        {
            for (int j = 0; j < 51; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << solve(0, 0, 0) << "\n";
    }
    return 0;
}
