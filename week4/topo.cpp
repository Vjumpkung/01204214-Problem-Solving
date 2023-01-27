#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool topo_sort(vector<vector<int>> &Graph, list<int> &in_ver, vector<int> &topo, int *in_degree)
{
    int cnt = 0;
    while (not in_ver.empty())
    {
        int current = in_ver.front();
        in_ver.pop_front();
        topo.push_back(current);
        for (unsigned int i = 0; i < Graph.at(current).size(); i++)
        {
            in_degree[Graph.at(current).at(i)]--;
            if (in_degree[Graph.at(current).at(i)] == 0)
            {
                in_ver.push_back(Graph.at(current).at(i));
            }
        }
        cnt++;
    }
    if (cnt != (int)Graph.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int vertex, edge;
    vector<vector<int>> Graph;
    cin >> vertex >> edge;
    Graph.resize(vertex);
    int vertex_in[vertex] = {0};
    int vertex_out[vertex] = {0};
    for (int i = 0; i < edge; i++)
    {
        int from, too;
        cin >> from >> too;
        Graph.at(from - 1).push_back(too - 1);
        vertex_in[too - 1] += 1;
        vertex_out[from - 1] += 1;
    }
    vector<int> topo;
    list<int> ver_in;
    for (int i = 0; i < vertex; i++)
    {
        if (vertex_in[i] == 0)
        {
            ver_in.push_back(i);
        }
    }
    if (topo_sort(Graph, ver_in, topo, vertex_in))
    {
        for (auto &i : topo)
        {
            cout << i + 1 << endl;
        }
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}