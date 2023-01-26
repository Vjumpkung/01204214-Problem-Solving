#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct edge
{
    int from, too;
    double weight;
};

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

bool cmp(edge a, edge b)
{
    return a.weight < b.weight;
}

int main()
{
    int n, m;
    vector<int> speed;
    vector<edge> edge_lst;
    cin >> n >> m;
    speed.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> speed.at(i);
    }
    for (int i = 0; i < m; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;
        edge_lst.push_back({f - 1, t - 1, ceil((0.0 + w) / (speed.at(f - 1) + speed.at(t - 1)))});
    }
    sort(edge_lst.begin(), edge_lst.end(), cmp);
    vector<int> s;
    vector<edge> select_edge;
    s.resize(n);
    double max_time = 0;
    for (uint i = 0; i < s.size(); i++)
    {
        s[i] = i;
    }
    for (auto i : edge_lst)
    {
        int u = find_set(i.from, s);
        int v = find_set(i.too, s);
        if (u != v)
        {
            select_edge.push_back(i);
            union_sets(u, v, s);
            max_time = max(max_time, i.weight);
        }
    }
    cout << (int)max_time << "\n";
    return 0;
}