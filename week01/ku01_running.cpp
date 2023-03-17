#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    int run[n];
    for (int i = 0; i < n; i++)
    {
        cin >> run[i];
    }
    int c = n;
    float rob = r;
    int minn = run[0];
    for (int i = 0; i < n; i++)
    {
        if (run[i] < minn)
        {
            minn = run[i];
        }
    }
    for (int j = 0; j < n; j++)
    {
        if ((minn * rob / minn) - (minn * rob / run[j]) > 1)
        {
            c--;
        }
    }
    cout << c;
    return 0;
}