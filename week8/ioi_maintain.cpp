#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
int vertex, edge;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> vertex >> edge;
    vector<int> arr(vertex);
    for (int i = 0; i < edge; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;
        edges.push_back({w, {f - 1, t - 1}});
        for (int i = 0; i < vertex; i++)
        {
            arr[i] = i;
        }
        int cost = 0;
        sort(edges.begin(), edges.end());
        int union_count = 0;
        for (auto &i : edges)
        {
            if (union_count == vertex - 1)
            {
                break;
            }
            int a = find_set(i.second.first, arr);
            int b = find_set(i.second.second, arr);
            if (a != b)
            {
                union_sets(a, b, arr);
                union_count++;
                cost += i.first;
            }
        }
        for (int i = 0; i < vertex - 1; i++)
        {
            if (find_set(i, arr) == find_set(i + 1, arr))
            {
                continue;
            }
            else
            {
                cost = -1;
            }
        }
        cout << cost << "\n";
    }
    return 0;
}