#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#define INF 0xfffffff

using namespace std;

int main()
{
    vector<vector<int>> graph;
    int N, M, K, H;
    cin >> N >> M >> K >> H;
    H *= 60;
    int types[2] = {60, 30};
    int hos[N];
    int visited[N][2];
    int dist[N][2];
    vector<int> hoslst;
    for (int i = 0; i < N; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
        visited[i][0] = 0;
        visited[i][1] = 0;
        hos[i] = -1;
    }
    graph.resize(N);
    for (int i = 0; i < K; i++)
    {
        int t;
        cin >> t;
        hos[t - 1] = 0;
        hoslst.push_back(t - 1);
    }
    for (auto i : hoslst)
    {
        int t;
        cin >> t;
        hos[i] = t;
    }
    for (int i = 0; i < M; i++)
    {
        int f, t;
        cin >> f >> t;
        graph.at(f - 1).push_back(t - 1);
        graph.at(t - 1).push_back(f - 1);
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        if (hos[i] != -1)
        {
            q.push({i, hos[i]});
            dist[i][hos[i]] = 0;
        }
    }
    while (not q.empty())
    {
        int current = q.front().first;
        int type = q.front().second;
        q.pop();
        if (dist[current][type] == H or visited[current][type])
        {
            continue;
        }
        visited[current][type] = 1;
        for (auto &i : graph.at(current))
        {
            if (dist[i][type] > dist[current][type] + types[type])
            {
                dist[i][type] = dist[current][type] + types[type];
                q.push({i, type});
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (min(dist[i][0], dist[i][1]) != INF)
        {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}