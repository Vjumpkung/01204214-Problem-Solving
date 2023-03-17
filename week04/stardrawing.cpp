#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int dfs_cycle(vector<vector<int>> &graph, int *visited, int parent, int current, int depth, map<int, int> &degree)
{
    int total = 0;
    int detect = 0;
    for (auto &i : graph.at(current))
    {
        if (not visited[i])
        {
            detect = 1;
            visited[i] = 1;
            total = dfs_cycle(graph, visited, parent, i, depth + 1, degree);
            visited[i] = 0;
        }
        if (total)
        {
            return total;
        }
    }
    if (degree[current] == 2 and not detect)
    {
        return depth;
    }
    return 0;
}

void dfs(vector<vector<int>> &v, int current, int *visited, vector<int> &data, vector<int> &total)
{
    if (visited[current])
    {
        return;
    }
    visited[current] = 1;
    for (int i = 0; i < (int)v[current].size(); i++)
    {
        if (not visited[v[current][i]])
        {
            data.push_back(v[current][i]);
            dfs(v, v[current][i], visited, data, total);
            if (data.size() > 0)
            {
                total.push_back((int)data.size());
            }
            data.clear();
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v;
    vector<pair<int, int>> dm;
    vector<int> data;
    vector<int> ans;
    set<vector<int>> answer;
    map<int, int> degree;
    int visited[n] = {0};
    int visited2[n] = {0};
    for (int i = 0; i < n; i++)
    {
        degree[i] = 0;
        visited[i] = 0;
        visited2[i] = 0;
    }
    v.resize(n);
    for (int i = 0; i < e; i++)
    {
        int f, t;
        cin >> f >> t;
        v[f - 1].push_back(t - 1);
        v[t - 1].push_back(f - 1);
        degree[f - 1]++;
        degree[t - 1]++;
    }
    for (auto i : degree)
    {
        dm.push_back({i.second, i.first});
    }
    sort(dm.rbegin(), dm.rend());
    int is_degree_0_exist = 0;
    for (auto i : dm)
    {
        int vertex_degree = i.first;
        int vertex = i.second;
        if (visited[vertex])
        {
            continue;
        }
        if (vertex_degree == 0)
        {
            is_degree_0_exist = 1;
        }
        dfs(v, vertex, visited, data, ans);
        visited2[vertex] = 1;
        int cycle_length = dfs_cycle(v, visited2, vertex, vertex, 0, degree);
        visited2[vertex] = 0;
        if (cycle_length)
        {
            for (auto &j : ans)
            {
                if (j == cycle_length)
                {
                    j += 100000;
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.size() > 0)
        {
            int summ = 0;
            if (vertex_degree == 2)
            {
                for (auto &h : ans)
                {
                    summ += h;
                }
                answer.insert({summ});
            }
            else
            {
                answer.insert(ans);
            }
        }
        ans.clear();
        data.clear();
    }
    if (is_degree_0_exist)
    {
        cout << answer.size() + 1 << "\n";
    }
    else
    {
        cout << answer.size() << "\n";
    }
    return 0;
}
