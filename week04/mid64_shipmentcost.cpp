#include <iostream>
#include <queue>
#include <vector>
#define INF 0xfffffff

using namespace std;

int lst[300010];
int travel[300000] = {0};
queue<int> q;

void bfs(vector<int> from, int *travel, vector<vector<int>> &Graph, int GraphSize, vector<int> &factory)
{
    for (auto &i : from)
    {
        q.push(i);
        travel[i] = 1;
    }
    vector<int> dist;
    dist.resize(GraphSize, 0);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        travel[current] = 1;
        for (unsigned int i = 0; i < Graph[current].size(); i++)
        {
            if (!travel[Graph[current].at(i)])
            {
                travel[Graph[current].at(i)] = 1;
                dist[Graph[current][i]] = dist[current] + 1;
                q.push(Graph[current].at(i));
            }
        }
    }
    for (auto &j : factory)
    {
        lst[j] = min(lst[j], dist[j]);
    }
}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<int> factory;
    vector<int> village;
    vector<vector<int>> graph;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int from, too;
        cin >> from >> too;
        graph.at(from - 1).push_back(too - 1);
        graph.at(too - 1).push_back(from - 1);
    }
    for (int i = 0; i < s; i++)
    {
        int val;
        cin >> val;
        village.push_back(val - 1);
    }
    for (int i = 0; i < t; i++)
    {
        int val;
        cin >> val;
        lst[val - 1] = INF;
        factory.push_back(val - 1);
    }
    bfs(village, travel, graph, graph.size(), factory);
    for (auto &i : factory)
    {
        cout << lst[i] << "\n";
    }
    return 0;
}
