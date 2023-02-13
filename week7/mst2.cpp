#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int a, b, w;
};

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> adj;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj.push_back({a - 1, b - 1, w});
    }
    sort(adj.begin(), adj.end(), cmp);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int a = find_set(adj[i].a, parent);
        int b = find_set(adj[i].b, parent);
        if (a != b)
        {
            sum += adj[i].w;
            union_sets(a, b, parent);
        }
    }
    cout << sum << endl;
    return 0;
}