#include <iostream>
#include <set>
#include <utility>
#include <vector>
#define INF 2147483647

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
        adj[b - 1].push_back({a - 1, w});
    }
    int parent[n];
    int key[n];
    bool inMST[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        inMST[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    set<pair<int, int>> q;
    q.insert({0, 0});
    while (!q.empty())
    {
        int u = q.begin()->second;
        q.erase(q.begin());
        inMST[u] = true;
        for (auto i : adj[u])
        {
            if (!inMST[i.first] && i.second < key[i.first])
            {
                q.erase({key[i.first], i.first});
                key[i.first] = i.second;
                q.insert({key[i.first], i.first});
                parent[i.first] = u;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += key[i];
    }
    cout << sum << endl;
    return 0;
}