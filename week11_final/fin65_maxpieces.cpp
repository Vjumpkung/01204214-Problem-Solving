#include <algorithm>
#include <iostream>

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

int main()
{
    fastio;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cumsum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cumsum[i] = cumsum[i - 1] + arr[i];
    }
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
            int yindex = lower_bound(arr, arr + n, Y) - arr - 1;
            X += cumsum[yindex];
            int index2 = lower_bound(cumsum, cumsum + n, X) - cumsum;
            if (X >= cumsum[index2] and index2 < n)
            {
                index2++;
            }
            cout << index2 - yindex - 1 << "\n";
        }
    }
    return 0;
}
