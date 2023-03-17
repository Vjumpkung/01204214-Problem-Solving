#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b;
    if (m == 1)
    {
        if (a[0] + 1 == n)
        {
            b.push_back(0);
        }
        else if (a[0] - 1 == n)
        {
            b.push_back(1);
        }
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] == 1)
            {
                b.push_back(1);
            }
            else if (a[i] - a[i - 1] == -1)
            {
                b.push_back(0);
            }
        }
    }
    else if (m == 2)
    {
        if (a[0] + 1 == n)
        {
            b.push_back(0);
        }
        else if (a[0] - 1 == n)
        {
            b.push_back(1);
        }
        vector<int> y = {a[0]};
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
            {
                if (a[i] - 2 * y[i - 1] > 0)
                {
                    y.push_back(a[i] - 2 * y[i - 1]);
                }
                else
                {
                    y.push_back(a[i] - y[i - 1]);
                }
            }
            else if (a[i] < a[i - 1])
            {
                y.push_back(a[i] - y[i - 1]);
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (y[i] - y[i - 1] == 1)
            {
                b.push_back(1);
            }
            else if (y[i] - y[i - 1] == -1)
            {
                b.push_back(0);
            }
        }
    }
    for (unsigned int i = 0; i < b.size(); i++)
    {
        cout << b.at(i) << "\n";
    }
    return 0;
}