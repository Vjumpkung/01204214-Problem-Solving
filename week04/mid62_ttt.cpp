#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int vertex, edges;
vector<pair<int, int>> v;

bool is_bipartite(vector<vector<int>> &Graph, int start, int *seek)
{
    queue<int> q;
    for (unsigned int i = start; i < Graph.size(); i++)
    {
        if (Graph.at(i).size() != 0 && seek[i] == -1)
        {
            seek[i] = 1;
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
            if (seek[Graph.at(current).at(i)] == -1)
            {
                seek[Graph.at(current).at(i)] = 1 - seek[current];
                q.push(Graph.at(current).at(i));
            }
            else if (seek[current] == seek[Graph.at(current).at(i)])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int mode, pair<int, int> select)
{
    vector<vector<int>> Graph;
    Graph.resize(vertex);
    for (auto &i : v)
    {
        if ((select.first == i.first and select.second == i.second) or (select.first == i.second and select.second == i.first))
        {
            continue;
        }
        else
        {
            Graph.at(i.first).push_back(i.second);
            Graph.at(i.second).push_back(i.first);
        }
    }
    int logic = 1;
    int arr[100000];
    for (unsigned int i = 0; i < Graph.size(); i++)
    {
        arr[i] = -1;
    }
    for (unsigned int i = 0; i < Graph.size(); i++)
    {
        if (Graph.at(i).size() != 0 && arr[i] == -1)
        {
            logic = logic & is_bipartite(Graph, i, arr);
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
    cin >> vertex >> edges;
    for (int i = 0; i < edges; i++)
    {
        int from, too;
        cin >> from >> too;
        v.push_back({from - 1, too - 1});
    }
    for (auto &i : v)
    {
        if (isBipartite(1, i))
        {
            cout << i.first + 1 << " " << i.second + 1 << "\n";
            break;
        }
    }
    return 0;
}
