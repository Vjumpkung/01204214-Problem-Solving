#include <iostream>

using namespace std;

int tree[1010];
int n, m;
int a, b;

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
        if (a == 1 or b == 1)
        {
            cout << 1 << "\n";
        }
        else if (tree[a] == b)
        {
            cout << b << "\n";
        }
        else if (tree[b] == a)
        {
            cout << a << "\n";
        }
        else
        {
            int x = -1;
            int found = 0;
            x = tree[a];
            while (not found and x != 1)
            {
                if (x == b)
                {
                    found = 1;
                    cout << x << "\n";
                    break;
                }
                else
                {
                    int temp = x;
                    x = tree[temp];
                }
            }
            if (not found)
            {
                x = tree[b];
                while (not found and x != 1)
                {
                    if (x == a)
                    {
                        found = 1;
                        cout << x << "\n";
                        break;
                    }
                    else
                    {
                        int temp = x;
                        x = tree[temp];
                    }
                }
            }
            if (not found)
            {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}