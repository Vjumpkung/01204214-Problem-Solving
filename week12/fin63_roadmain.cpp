#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int MAX_N = 100000;

vector<tuple<int, int, int, int>> edges;

int arr[MAX_N];
int n, m;

int find_set(int x)
{
    if (x == arr[x])
    {
        return x;
    }
    return arr[x] = find_set(arr[x]);
}

void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if (x != y)
    {
        arr[x] = y;
    }
}

void init_set()
{
    for (int i = 0; i < MAX_N; ++i)
    {
        arr[i] = i;
    }
}

int main()
{
    init_set();
    cin >> n >> m;
    int union_count = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        edges.push_back(make_tuple(c, d, a, b));
        if (d == 1)
        {
            if (find_set(a) != find_set(b))
            {
                union_set(a, b);
                union_count++;
            }
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (union_count >= n - 1)
        {
            break;
        }
        int weight, type, a, b;
        tie(weight, type, a, b) = edges[i];
        if (type == 0 && find_set(a) != find_set(b))
        {
            union_set(a, b);
            union_count++;
            ans += weight;
        }
    }
    cout << ans << "\n";
    return 0;
}