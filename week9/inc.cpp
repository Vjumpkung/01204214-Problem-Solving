#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> sub;
vector<int> dp;

int lengthOfLIS(vector<int> &nums)
{
    // with given sequence
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sub.push_back(-1);
        dp.push_back(1);
    }
    if (n == 0)
        return 0;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                // cout << i << " " << j << "\n";
                if (dp[i] < dp[j] + 1)
                {
                    sub[i] = j;
                }
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << lengthOfLIS(arr) << endl;
    // print dp
    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // get max of dp with index
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > dp[maxx])
        {
            maxx = i;
        }
    }
    // cout << "\n";
    vector<int> res;
    int j = maxx;
    res.push_back(j);
    while (sub[j] != -1)
    {
        // cout << sub[j] << " ";
        j = sub[j];
        res.push_back(j);
    }
    // cout << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << arr[res[i]] << " ";
    }
    cout << "\n";
    return 0;
}