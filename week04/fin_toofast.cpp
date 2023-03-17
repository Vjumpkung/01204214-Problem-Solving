#include <iostream>
#include <queue>
#include <vector>
#define INF 0xfffffff

using namespace std;

struct road
{
    int weight;
    int vertex;
    int express;
};

struct compare_road
{
    bool operator()(road const &r1, road const &r2)
    {
        return r1.weight > r2.weight;
    }
};

int shortest_path(vector<vector<road>> &Graph, int GraphSize, int source)
{
    int dist[GraphSize][2], f[GraphSize][2];
    priority_queue<road, vector<road>, compare_road> pq;
    for (int i = 0; i < GraphSize; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
        f[i][0] = 0;
        f[i][1] = 0;
    }
    dist[0][0] = 0;
    pq.push({0, source, 0});

    while (not pq.empty())
    {
        int u = pq.top().vertex;
        int come_from_express = pq.top().express;
        pq.pop();
        if (f[u][come_from_express])
        {
            continue;
        }
        f[u][come_from_express] = true;
        for (auto &i : Graph.at(u))
        {
            int v = i.vertex;
            int weight = i.weight;
            int express = i.express;
            if (not express)
            {
                if (f[v][come_from_express] == 0 and dist[v][come_from_express] > dist[u][come_from_express] + weight)
                {
                    dist[v][come_from_express] = dist[u][come_from_express] + weight;
                    pq.push({dist[v][come_from_express], v, come_from_express});
                }
            }
            else if (not come_from_express)
            {
                if (f[v][1] == 0 and dist[v][1] > dist[u][come_from_express] + weight)
                {
                    dist[v][1] = dist[u][come_from_express] + weight;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
    if (dist[Graph.size() - 1][0] == INF and dist[Graph.size() - 1][0] == INF)
    {
        return -1;
    }
    return min(dist[Graph.size() - 1][0], dist[Graph.size() - 1][1]);
}

int main()
{
    int n, m;
    int from, too, time, isExpress;
    cin >> n >> m;
    vector<vector<road>> graph;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> from >> too >> time >> isExpress;
        graph.at(from - 1).push_back({time, too - 1, isExpress});
        graph.at(too - 1).push_back({time, from - 1, isExpress});
    }
    int sp = shortest_path(graph, graph.size(), 0);
    cout << sp << "\n";
    return 0;
}