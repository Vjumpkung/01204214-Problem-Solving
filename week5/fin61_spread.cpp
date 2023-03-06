#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

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
    vector<int> speed;
    vector<tuple<double, int, int>> edge_lst;
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
        edge_lst.push_back({ceil((0.0 + w) / (speed.at(f - 1) + speed.at(t - 1))), f - 1, t - 1});
    }
    sort(edge_lst.begin(), edge_lst.end());
    vector<int> s;
    vector<tuple<double, int, int>> select_edge;
    s.resize(n);
    double max_time = 0;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        s[i] = i;
    }
    for (auto i : edge_lst)
    {
        int u = find_set(get<1>(i), s);
        int v = find_set(get<2>(i), s);
        if (u != v)
        {
            select_edge.push_back(i);
            union_sets(u, v, s);
            max_time = max(max_time, get<0>(i));
        }
    }
    cout << (int)max_time << "\n";
    return 0;
}