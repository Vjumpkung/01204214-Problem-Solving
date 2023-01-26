#include <iostream>
#include <set>
#include <utility>
#include <vector>
#define INF 0xfffffff

using namespace std;

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
    set<pair<int, int>> pq;
    vector<int> distance(graph.size(), INF);
    vector<bool> visited(graph.size(), false);
    pq.insert({0, 0});
    distance.at(0) = 0;
    while (!pq.empty())
    {
        int u = (*pq.begin()).second;
        pq.erase(pq.begin());
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        for (auto i : graph.at(u))
        {
            int v = i.second;
            int weight = i.first;
            if (visited[v] == false and distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                pq.insert({distance[v], v});
            }
        }
    }
    cout << distance[graph.size() - 1] << endl;
    return 0;
}