#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct vertex
{
    int node;
    int color;
};

struct current
{
    int vertex;
    int choose_color;
};

int visited[50001][3];
int dist[50001][3];
vector<vector<vertex>> graph;
int n, m, s, t;
queue<current> q;

int main()
{
    cin >> n >> m >> s >> t;
    s--;
    t--;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int from, too, colour;
        cin >> from >> too >> colour;
        graph.at(from - 1).push_back({too - 1, colour});
        graph.at(too - 1).push_back({from - 1, colour});
    }
    for (int i = 0; i < n; i++)
    {
        visited[i][0] = 0;
        visited[i][1] = 0;
        visited[i][2] = 0;
        dist[i][0] = 0;
        dist[i][1] = 0;
        dist[i][2] = 0;
    }
    q.push({s, 0});
    while (not q.empty())
    {
        int current = q.front().vertex;
        int choose_color = q.front().choose_color;
        q.pop();
        visited[current][choose_color] = 1;
        for (auto &i : graph.at(current))
        {
            if (i.color == 0 and not visited[i.node][choose_color])
            {
                dist[i.node][choose_color] = dist[current][choose_color] + 1;
                visited[i.node][choose_color] = 1;
                q.push({i.node, choose_color});
            }
            else if (i.color > 0 and choose_color == 0 and not visited[i.node][i.color])
            {
                dist[i.node][i.color] = dist[current][choose_color] + 1;
                visited[i.node][i.color] = 1;
                q.push({i.node, i.color});
            }
            else if (choose_color > 0 and i.color == choose_color and not visited[i.node][choose_color])
            {
                dist[i.node][choose_color] = dist[current][choose_color] + 1;
                visited[i.node][choose_color] = 1;
                q.push({i.node, choose_color});
            }
        }
    }
    int minn = 0xfffffff;
    for (int i = 0; i < 3; i++)
    {
        if (dist[t][i] < minn and dist[t][i] != 0)
        {
            minn = dist[t][i];
        }
    }
    if (minn == 0xfffffff)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << minn << "\n";
    }
    return 0;
}