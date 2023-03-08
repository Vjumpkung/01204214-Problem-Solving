#include <iostream>

using namespace std;

int n;
int p[100001][2];
int storage[100001][2];

/*
mode 0 = coffee
mode 1 = bakery
*/

int star(int idx, int mode)
{
    if (storage[idx][mode] != -1)
    {
        return storage[idx][mode];
    }
    if (idx > n - 1)
    {
        return 0;
    }
    else
    {
        int a, b, c, d, e;
        int maxx = -10001;
        if (mode == 0)
        {
            a = star(idx + 1, 1);
        }
        else
        {
            a = star(idx + 1, 0);
        }
        maxx = max(maxx, a);
        b = star(idx + 2, 0);
        maxx = max(maxx, b);
        c = star(idx + 2, 1);
        maxx = max(maxx, c);
        d = star(idx + 3, 0);
        maxx = max(maxx, d);
        e = star(idx + 3, 1);
        maxx = max(maxx, e);
        storage[idx][mode] = maxx + p[idx][mode];
        return storage[idx][mode];
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i][0] >> p[i][1];
        storage[i][0] = -1;
        storage[i][1] = -1;
    }
    int ans2 = max(star(0, 0), star(0, 1));
    int ans1 = max(star(1, 0), star(1, 1));
    if (ans2 < 0 and ans1 < 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    cout << max(ans2, ans1) << "\n";
    return 0;
}
