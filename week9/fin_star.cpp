#include <iostream>

using namespace std;

int n;
pair<int, int> p[100001];
int storage[100001][3];

/*
mode 1 = coffee
mode 2 = bakery
*/

int star(int idx, int mode)
{
    if (storage[idx][mode] != -1)
    {
        return storage[idx][mode];
    }
    if (idx >= n)
    {
        return 0;
    }
    else
    {
        int a = star(idx + 2, 0);
        int b = star(idx + 3, 0);
        storage[idx][0] = p[idx].first + max(a, b);
        return storage[idx][0];
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
        storage[i][0] = -1;
        storage[i][1] = -1;
        storage[i][2] = -1;
    }
    int ans1 = max(star(0, 0), star(1, 0));
    cout << ans1 << "\n";
    return 0;
}
