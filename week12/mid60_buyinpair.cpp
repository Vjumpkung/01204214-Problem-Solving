#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int lld;

lld n;
lld arr[200000];
lld countPairSum(lld L, lld R, lld N)
{
    sort(arr, arr + N);
    lld right = N - 1, count = 0;
    while (right > 0)
    {
        auto it1 = lower_bound(arr, arr + N, L - arr[right]);
        lld start = it1 - arr;
        auto it2 = upper_bound(arr, arr + N, R - arr[right]);
        --it2;
        lld end = it2 - arr;
        end = min(end, right - 1);
        if (end - start >= 0)
        {
            count += (end - start + 1);
        }
        right--;
    }
    return count;
}

int main()
{
    lld L, R;
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << countPairSum(L, R, n) << "\n";
    return 0;
}
