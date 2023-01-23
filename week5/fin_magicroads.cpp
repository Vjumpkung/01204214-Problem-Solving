#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_N = 100001;

using namespace std;

int n, m, k, h;

int school[MAX_N] = {0};

int visited[MAX_N][2] = {0};

int dist[MAX_N][2] = {0};

int main()
{
    cin >> n >> m >> k >> h;
    vector<vector<pair<int, int>>> graph;
    vector<int> school_lst;
    graph.resize(n);
    for (int i = 0; i < k; i++)
    {
        int w;
        cin >> w;
        school[w - 1] = 1;
        school_lst.push_back(w - 1);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, p;
        cin >> u >> v >> p;
        graph.at(u - 1).push_back({v - 1, p});
        graph.at(v - 1).push_back({u - 1, p});
    }
    for (int i = 0; i < n; i++)
    {
        visited[i][0] = 0;
        visited[i][1] = 0;
        dist[i][0] = MAX_N;
        dist[i][1] = MAX_N;
    }
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (not q.empty())
    {
        int current = q.front().first;
        q.pop();
        if (h < dist[current][0])
        {
            continue;
        }
        visited[current][0] = 1;
        for (auto i : graph[current])
        {
            int v = i.first;
            int is_magic_road = i.second;
            if (dist[v][0] > dist[current][0] + 1 and is_magic_road == 0)
            {
                dist[v][0] = dist[current][0] + 1;
                q.push({v, 0});
            }
        }
    }
    for (auto a : school_lst)
    {
        if (visited[a][0])
        {
            dist[a][1] = dist[a][0];
            q.push({a, 1});
        }
    }
    while (not q.empty())
    {
        int current = q.front().first;
        visited[current][1] = 1;
        q.pop();
        if (h < dist[current][1])
        {
            continue;
        }
        for (auto i : graph[current])
        {
            int v = i.first;
            if (dist[v][1] > dist[current][1] + 1)
            {
                dist[v][1] = dist[current][1] + 1;
                q.push(i);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist[i][0] != -1 and dist[i][1] != -1 and h >= min(dist[i][0], dist[i][1]))
        {
            count++;
        }
        else if (dist[i][0] != -1 and h >= dist[i][0])
        {
            count++;
        }
        else if (dist[i][1] != -1 and h >= dist[i][1])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}