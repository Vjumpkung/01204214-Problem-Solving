#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#define INF 0xfffffffffffffff

using namespace std;

typedef long long int lld;

vector<lld> arr(100000, 0);
vector<lld> arr2(100000, 0);

int bsearch(vector<pair<lld, lld>> &sorted_vec, lld num, int numidx, lld center, int n)
{
    lld mid = -1;
    lld low = 0, high = n;
    while (1)
    {
        mid = low + (high - low) / 2;
        if (sorted_vec[mid].first == num)
        {
            break;
        }
        if (sorted_vec[mid].first < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    int running = 0, running2 = 0;
    if (mid > 0 and mid < n)
    {
        int move_failed_1 = 0, move_failed_2 = 0;
        while (abs(sorted_vec[mid + running].second - numidx) <= 1)
        {
            if (mid + running + 1 > n)
            {
                move_failed_1 = 1;
                break;
            }
            running++;
        }
        while (abs(sorted_vec[mid - running2].second - numidx) <= 1)
        {
            if (mid - running2 - 1 < 0)
            {
                move_failed_2 = 1;
                break;
            }
            running2++;
        }
        if (not(move_failed_1 or move_failed_2))
        {
            lld tmp1 = 0, tmp2 = 0;
            if (numidx == 0)
            {
                tmp1 = abs(arr[numidx + 1] - sorted_vec[mid + running].first);
                tmp2 = abs(arr[numidx + 1] - sorted_vec[mid - running2].first);
            }
            else if (numidx > 0 and numidx < n - 1)
            {
                tmp1 = abs(arr[numidx - 1] - sorted_vec[mid + running].first) + abs(arr[numidx + 1] - sorted_vec[mid + running].first);
                tmp2 = abs(arr[numidx - 1] - sorted_vec[mid - running2].first) + abs(arr[numidx + 1] - sorted_vec[mid - running2].first);
            }
            else
            {
                tmp1 = abs(arr[numidx - 1] - sorted_vec[mid + running].first);
                tmp2 = abs(arr[numidx - 1] - sorted_vec[mid - running2].first);
            }
            if (tmp1 > tmp2)
            {
                return mid - running2;
            }
            else
            {
                return mid + running;
            }
        }
        else if (not move_failed_1)
        {
            return mid + running;
        }
        else
        {
            return mid - running2;
        }
    }
    else if (mid == 0)
    {
        while (abs(sorted_vec[mid + running].second - numidx) <= 1)
        {
            if (mid + running + 1 > n)
            {
                break;
            }
            running++;
        }
        return mid + running;
    }
    else
    {
        while (abs(sorted_vec[mid - running2].second - numidx) <= 1)
        {
            if (mid - running2 - 1 < 0)
            {
                break;
            }
            running2++;
        }
        return mid - running2;
    }
}

int main()
{
    int n;
    int record_idx = 0;
    int iii = 0;
    cin >> n;
    vector<pair<lld, lld>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v.push_back({arr[i], i});
        arr2[i] = arr[i];
    }
    sort(v.begin(), v.end());
    lld t = 0;
    for (int k = 0; k < n - 1; k++)
    {
        t += abs(arr[k] - arr[k + 1]);
    }
    lld sum_of_min_diff = t;
    for (int i = 0; i < n; i++)
    {
        lld idx = 0, candidate1 = INF, candidate2 = INF;
        if (i == 0)
        {
            candidate1 = arr[i + 1];
            idx = v[bsearch(v, candidate1, i, arr[i], n)].second;
        }
        else if (i > 0 and i < n - 1)
        {
            candidate1 = arr[i + 1];
            int idx1 = v[bsearch(v, candidate1, i, arr[i], n)].second;
            candidate2 = arr[i - 1];
            int idx2 = v[bsearch(v, candidate2, i, arr[i], n)].second;
            lld tmp1 = abs(arr[idx1] - arr[i + 1]) + abs(arr[idx1] - arr[i - 1]);
            lld tmp2 = abs(arr[idx2] - arr[i + 1]) + abs(arr[idx2] - arr[i - 1]);
            if (tmp1 > tmp2)
            {
                idx = idx2;
            }
            else
            {
                idx = idx1;
            }
        }
        else
        {
            candidate2 = arr[i - 1];
            idx = v[bsearch(v, candidate2, i, arr[i], n)].second;
        }
        arr2[i] = arr[idx];
        lld new_sum = 0;
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
            lld new_diff = abs(arr2[i] - arr2[i - 1]);
            lld old_diff = abs(arr[i] - arr[i - 1]);
            new_sum = t - old_diff + new_diff;
        }
        if (new_sum < sum_of_min_diff)
        {
            iii = i;
            record_idx = idx;
        }
        sum_of_min_diff = min(new_sum, sum_of_min_diff);
        arr2[i] = arr[i];
    }
    cout << sum_of_min_diff << "\n";
    return 0;
}