#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int is_bipartite(vector<vector<int>> &Graph, int start, int *arr)
{
    queue<int> q;
    for (unsigned int i = start; i < Graph.size(); i++)
    {
        if (Graph.at(i).size() != 0 && arr[i] == -1)
        {
            arr[i] = 1;
            q.push(i);
            break;
        }
    }
    while (not q.empty())
    {
        int current = q.front();
        q.pop();
        for (unsigned int i = 0; i < Graph.at(current).size(); i++)
        {
            if (current == Graph.at(current).at(i))
            {
                return false;
            }
            if (arr[Graph.at(current).at(i)] == -1)
            {
                arr[Graph.at(current).at(i)] = 1 - arr[current];
                q.push(Graph.at(current).at(i));
            }
            else if (arr[current] == arr[Graph.at(current).at(i)])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &Graph, vector<int> &more_than_k)
{
    int logic = 1;
    int arr[100000];
    for (unsigned int i = 0; i < Graph.size(); i++)
    {
        arr[i] = -1;
    }
    for (unsigned int i = 0; i < Graph.size(); i++)
    {
        if (more_than_k[i])
        {
            continue;
        }
        if (Graph.at(i).size() != 0 && arr[i] == -1)
        {
            logic = logic and is_bipartite(Graph, i, arr);
            if (logic == 0)
            {
                return logic;
            }
        }
    }
    return logic;
}

int main()
{
    vector<vector<int>> graph;
    vector<pair<int, int>> edges;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> degree(n, 0);
    vector<int> more_than_k(n, 0);
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        edges.push_back({f - 1, t - 1});
        degree[f - 1]++;
        degree[t - 1]++;
    }
    for (unsigned int i = 0; i < degree.size(); i++)
    {
        if (degree[i] >= k)
        {
            more_than_k[i] = 1;
        }
    }
    for (auto &i : edges)
    {
        if (more_than_k[i.first] or more_than_k[i.second])
        {
            continue;
        }
        graph.at(i.first).push_back(i.second);
        graph.at(i.second).push_back(i.first);
    }
    if (isBipartite(graph, more_than_k))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}