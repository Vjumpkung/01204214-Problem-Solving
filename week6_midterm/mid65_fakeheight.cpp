#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#define INF 0xfffffffffffffff;

using namespace std;

typedef long long int lld;

int main()
{
    int n;
    cin >> n;
    vector<lld> arr(n, 0);
    vector<pair<lld, lld>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v.push_back({arr[i], i});
    }
    lld t = 0;
    for (int k = 0; k < arr.size() - 1; k++)
    {
        t += abs(arr[k] - arr[k + 1]);
    }
    lld sum_of_min_diff = t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(i - j) == 1 or i - j == 0 or i > j)
            {
                continue;
            }
            vector<lld> arr2 = arr;
            vector<lld> arr3 = arr;
            arr2[i] = arr2[j];
            arr3[j] = arr3[i];
            lld new_sum = 0;
            lld new_sum2 = 0;
            if (i == 0)
            {
                lld new_diff = abs(arr2[i] - arr2[i + 1]);
                lld old_diff = abs(arr[i] - arr[i + 1]);
                new_sum = t - old_diff + new_diff;
            }
            else if (i > 0 and i < n - 1)
            {
                lld new_diff = abs(arr2[i - 1] - arr2[i]) + abs(arr2[i] - arr2[i + 1]);
                lld old_diff = abs(arr[i - 1] - arr[i]) + abs(arr[i] - arr[i + 1]);
                new_sum = t - old_diff + new_diff;
            }
            else
            {
                lld new_diff = abs(arr3[j] - arr3[j - 1]);
                lld old_diff = abs(arr[j] - arr[j - 1]);
                new_sum = t - old_diff + new_diff;
            }
            if (j == 0)
            {
                lld new_diff = abs(arr3[j] - arr3[j + 1]);
                lld old_diff = abs(arr[j] - arr[j + 1]);
                new_sum2 = t - old_diff + new_diff;
            }
            else if (j > 0 and j < n - 1)
            {
                lld new_diff = abs(arr3[j - 1] - arr3[j]) + abs(arr3[j] - arr3[j + 1]);
                lld old_diff = abs(arr[j - 1] - arr[j]) + abs(arr[j] - arr[j + 1]);
                new_sum2 = t - old_diff + new_diff;
            }
            else
            {
                lld new_diff = abs(arr3[j] - arr3[j - 1]);
                lld old_diff = abs(arr[j] - arr[j - 1]);
                new_sum2 = t - old_diff + new_diff;
            }
            sum_of_min_diff = min(new_sum, sum_of_min_diff);
            sum_of_min_diff = min(new_sum2, sum_of_min_diff);
        }
    }
    cout << sum_of_min_diff << "\n";
    return 0;
}