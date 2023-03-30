#include <iostream>
#include <algorithm>

using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

const int MAX_N = 100000;
int X, Y;
int n, q;
int arr[MAX_N];
int cumsum[MAX_N];
int temp[MAX_N];

int dp[MAX_N];
int solve(int total, int idx)
{
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    else
    {
        int ans = 0;
        if (total + arr[idx] <= X and arr[idx] >= Y)
        {
            ans = max(ans, 1 + solve(total + arr[idx], idx + 1));
        }
        ans = max(ans, solve(total, idx + 1));
        return dp[idx] = ans;
    }
}

int main()
{
    fastio;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    // cumsum
    cumsum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cumsum[i] = cumsum[i - 1] + arr[i];
    }
    // // print cumsum and arr
    // for (int i = 0; i < n; i++)
    // {
    //     cout << cumsum[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < q; i++)
    {
        cin >> X >> Y;
        if (Y == 0)
        {
            // binary search give index
            int index = lower_bound(cumsum, cumsum + n, X) - cumsum;
            if (X >= cumsum[index] and index < n)
            {
                index++;
            }
            cout << index << "\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                dp[i] = -1;
            }
            cout << solve(0, 0) << "\n";
        }
    }
    return 0;
}
