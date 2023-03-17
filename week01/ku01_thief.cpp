#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, t;
    cin >> n >> k >> t;
    int idx = 0;
    t--;
    int travel[n] = {1, 0};
    while ((idx != t) && (travel[0] < 2))
    {
        idx = (idx + k) % n;
        travel[idx]++;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (travel[i] > 0)
        {
            c++;
        }
    }
    cout << c;
    return 0;
}