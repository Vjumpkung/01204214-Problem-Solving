#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[301] = {0};
    int n, c;
    cin >> n;
    int maxx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        arr[c]++;
    }
    for (int i = 0; i < 301; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    cout << maxx << endl;
    return 0;
}