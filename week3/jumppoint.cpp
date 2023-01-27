#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void bfs(int from, int too, int *travel, vector<int> *Graph, int GraphSize)
{
    queue<int> q;
    int end = 0;
    q.push(from);
    travel[from] = 1;
    int dist[GraphSize] = {0};
    for (int i = 0; i < GraphSize; i++)
    {
        dist[i] = 0;
    }
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
                if (Graph[current].at(i) == too)
                {
                    end = 1;
                    break;
                }
            }
        }
        if (end)
        {
            break;
        }
    }
    if (dist[GraphSize - 1] == 0)
    {
        cout << -1;
    }
    else
    {
        cout << dist[GraphSize - 1];
    }
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> p;
    vector<int> Graph[n + 2];
    int travelled[n + 2] = {0};
    int GraphSize = n + 2;
    p.push_back({0, 0});
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    p.push_back({100, 100});
    int dispower2 = w * w;
    for (unsigned int i = 0; i < p.size(); i++)
    {
        for (unsigned int j = i; j < p.size(); j++)
        {
            int z = pow(p.at(i).first - p.at(j).first, 2) + pow(p.at(i).second - p.at(j).second, 2);
            if (i == j)
            {
                continue;
            }
            if (z <= dispower2)
            {
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        }
    }
    bfs(0, GraphSize - 1, travelled, Graph, GraphSize);
    return 0;
}