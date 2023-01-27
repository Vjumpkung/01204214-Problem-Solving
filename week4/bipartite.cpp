#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
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
    bool isBipartite(vector<vector<int>> &Graph)
    {
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
};

int main()
{
    int rounds;
    cin >> rounds;
    for (int i = 0; i < rounds; i++)
    {
        int vertex, edges;
        cin >> vertex >> edges;
        vector<vector<int>> Graph;
        Graph.resize(vertex);
        for (int i = 0; i < edges; i++)
        {
            int from, too;
            cin >> from >> too;
            Graph.at(from - 1).push_back(too - 1);
            Graph.at(too - 1).push_back(from - 1);
        }
        if (Solution().isBipartite(Graph))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        Graph.clear();
    }
    return 0;
}