#include <bits/stdc++.h>

using namespace std;

double distance(int x, int y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{
    int n;
    cin >> n;
    int tx, ty, s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tx >> ty;
        double dis = distance(tx, ty);
        if (dis <= 2)
        {
            s += 5;
        }
        else if (dis <= 4)
        {
            s += 4;
        }
        else if (dis <= 6)
        {
            s += 3;
        }
        else if (dis <= 8)
        {
            s += 2;
        }
        else if (dis <= 10)
        {
            s += 1;
        }
    }
    cout << s;
    return 0;
}