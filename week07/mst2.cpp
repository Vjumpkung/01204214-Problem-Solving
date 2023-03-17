#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

using namespace std;

const int MAX_N = 100001;

int n, m;
vector<int> parent(MAX_N);
vector<tuple<int, int, int>> adj;

int find_set(int v, vector<int> &arr)
{
    if (v == arr[v])
    {
        return v;
    }
    return arr[v] = find_set(arr[v], arr);
}

void union_sets(int a, int b, vector<int> &arr)
{
    if (a != b)
    {
        arr[b] = a;
    }
}

void init_set(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj.push_back({w, a - 1, b - 1});
    }
    sort(adj.begin(), adj.end());
    init_set(parent);
    int sum = 0;
    int union_count = 0;
    for (int i = 0; i < m; i++)
    {
        if (union_count == n - 1)
            break;
        int a = find_set(get<1>(adj[i]), parent);
        int b = find_set(get<2>(adj[i]), parent);
        if (a != b)
        {
            sum += get<0>(adj[i]);
            union_sets(a, b, parent);
            union_count++;
        }
    }
    cout << sum << "\n";
    return 0;
}