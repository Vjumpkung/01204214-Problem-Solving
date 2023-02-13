#include <iostream>

using namespace std;

int find_set(int x, int *parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = find_set(parent[x], parent);
    }
}

void union_set(int x, int y, int *parent)
{
    parent[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < q; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        int x = find_set(a - 1, arr);
        int y = find_set(b - 1, arr);
        if (c == 'q')
        {
            if (x == y)
            {
                cout << "yes"
                     << "\n";
            }
            else
            {
                cout << "no"
                     << "\n";
            }
        }
        else
        {
            if (x != y)
            {
                union_set(x, y, arr);
            }
        }
    }
    return 0;
}