#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m, h;
    int maxx = -1;
    cin >> n >> m >> h;
    vector<vector<int>> graph;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int from, too;
        cin >> from >> too;
        graph.at(from - 1).push_back(too - 1);
        graph.at(too - 1).push_back(from - 1);
    }
    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        int dist[graph.size()] = {0};
        int visited[graph.size()] = {0};
        q.push(i);
        while (not q.empty())
        {
            int current = q.front();
            q.pop();
            visited[current] = 1;
            if (dist[current] == h)
            {
                break;
            }
            for (auto &a : graph[current])
            {
                if (not visited[a])
                {
                    visited[a] = 1;
                    dist[a] = dist[current] + 1;
                    q.push(a);
                }
            }
        }
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[j] != 0)
            {
                count++;
            }
        }
        maxx = max(maxx, count);
    }
    cout << maxx + 1 << "\n";
    return 0;
}