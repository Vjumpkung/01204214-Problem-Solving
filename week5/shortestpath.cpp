#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF 0xfffffff

using namespace std;

int shortest_path(vector<vector<pair<int, int>>> &Graph, int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(Graph.size(), INF);
    pq.push({0, source});
    distance[source] = 0;
    vector<bool> f(Graph.size(), false);
    while (not pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (f[u])
        {
            continue;
        }
        f[u] = true;
        for (auto &i : Graph.at(u))
        {
            int v = i.second;
            int weight = i.first;
            if (f[v] == false and distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    return distance[Graph.size() - 1];
}

int main()
{
    int n, m;
    int from, too, weight;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> from >> too >> weight;
        graph.at(from - 1).push_back({weight, too - 1});
        graph.at(too - 1).push_back({weight, from - 1});
    }
    cout << shortest_path(graph, 0) << endl;
    return 0;
}
