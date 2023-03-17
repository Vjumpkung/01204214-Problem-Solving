#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> *Mapping, int node, int *visited, int c)
{
    if (visited[node] == 0)
    {
        visited[node] = c;
    }
    if (!visited[Mapping[node][0]])
    {
        dfs(Mapping, Mapping[node][0], visited, c);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> Graph[n];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        Graph[i].push_back(a - 1);
    }
    int visited[n] = {0};
    for (int i = 1; i <= n; i++)
    {
        dfs(Graph, i - 1, visited, i);
    }

    int counting[n] = {0};

    for (int i = 0; i < n; i++)
    {
        counting[visited[i]]++;
    }

    int maxx = -1;

    for (int i = 0; i < n; i++)
    {
        if (counting[i] > maxx)
        {
            maxx = counting[i];
        }
    }

    cout << maxx;

    return 0;
}