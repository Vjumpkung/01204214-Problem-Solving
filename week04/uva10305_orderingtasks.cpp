#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int first_time = 1;

int main()
{
    while (1)
    {
        int n, m;
        queue<int> q;
        cin >> n >> m;
        if (n == 0 and m == 0)
        {
            cout << endl;
            break;
        }
        if (first_time > 1)
        {
            cout << endl;
        }
        first_time++;
        vector<vector<int>> graph;
        graph.resize(n);
        int in_deg[n] = {0};
        for (int i = 0; i < m; i++)
        {
            int from, too;
            cin >> from >> too;
            graph.at(from - 1).push_back(too - 1);
            in_deg[too - 1]++;
        }
        for (int i = 0; i < (int)graph.size(); i++)
        {
            if (in_deg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (not q.empty())
        {
            int current = q.front();
            q.pop();
            ans.push_back(current + 1);
            for (unsigned int i = 0; i < graph.at(current).size(); i++)
            {
                in_deg[graph.at(current).at(i)]--;
                if (in_deg[graph.at(current).at(i)] == 0)
                {
                    q.push(graph.at(current).at(i));
                }
            }
        }
        for (unsigned int i = 0; i < ans.size() - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[ans.size() - 1];
        ans.clear();
    }
    return 0;
}