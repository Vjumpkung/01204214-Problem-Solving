#include <iostream>

using namespace std;

int tree[1010];
int n, m;
int a, b;

bool find_path(int x, int y)
{
    if (x == y)
    {
        return true;
    }
    else if (x == 1)
    {
        return false;
    }
    else
    {
        return find_path(tree[x], y);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        cin >> tree[i];
    }
    while (m--)
    {
        cin >> a >> b;
        if (find_path(a, b))
        {
            cout << b << "\n";
        }
        else if (find_path(b, a))
        {
            cout << a << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}