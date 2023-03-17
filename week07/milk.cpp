#include <iostream>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

using namespace std;

const int MAX_N = 100001;

int n, q;
int arr[MAX_N];
int set_size[MAX_N];

int find_set(int x, int *parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    parent[x] = find_set(parent[x], parent);
    return parent[x];
}

void union_set(int x, int y, int *parent)
{
    int a = find_set(x, parent);
    int b = find_set(y, parent);
    if (set_size[a] > set_size[b])
    {
        swap(a, b);
    }
    parent[a] = b;
    set_size[b] += set_size[a];
}

void init_set(int *parent)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        set_size[i] = 1;
    }
}

void print(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        putchar(s[i]);
    }
    putchar('\n');
}

int main()
{
    fastio;
    cin >> n >> q;
    init_set(arr);
    for (int i = 0; i < q; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        int x = find_set(a - 1, arr);
        int y = find_set(b - 1, arr);
        switch (c)
        {
        case 'q':
            if (x == y)
            {
                print("yes");
            }
            else
            {
                print("no");
            }
            break;

        case 'c':
            if (x != y)
            {
                union_set(x, y, arr);
            }
            break;
        }
    }
    return 0;
}
