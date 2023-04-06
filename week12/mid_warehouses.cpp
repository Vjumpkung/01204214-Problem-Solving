#include <iostream>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

// union find

const int MAX_N = 100000;

int arr[MAX_N];
int n, m, q;

int find_set(int x)
{
    if (arr[x] == x)
    {
        return x;
    }
    else
    {
        return arr[x] = find_set(arr[x]);
    }
}

void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    arr[x] = y;
}

void init_set()
{
    for (int i = 0; i < 100000; i++)
    {
        arr[i] = i;
    }
}

void read_input()
{
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
    }
}

void question()
{
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (find_set(a) == find_set(b))
        {
            cout << "1"
                 << "\n";
        }
        else
        {
            cout << "0"
                 << "\n";
        }
    }
}

int main()
{
    fastio;
    init_set();
    read_input();
    question();
    return 0;
}