#include <cstdio>
#include <set>
#include <vector>
const int INF = 0xfffffff;

using namespace std;

void printi(int num, char end)
{
    int i = num;
    int t;
    char cx;
    int a = 0;
    char temp[100];
    while (i != 0)
    {
        t = i % 10;
        i = i / 10;
        temp[a] = t + '0';
        a++;
    }
    for (i = a - 1; i >= 0; i--)
    {
        cx = temp[i];
        putchar(cx);
    }
    putchar(end);
}

int geti()
{
    int i = 0;
    char c;
    while ((c = getchar()) != ' ' && c != '\n')
    {
        i = i * 10 + c - '0';
    }
    return i;
}

int main()
{
    int n, m;
    int from, too, weight;
    n = geti();
    m = geti();
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        from = geti();
        too = geti();
        weight = geti();
        graph.at(from - 1).push_back({weight, too - 1});
        graph.at(too - 1).push_back({weight, from - 1});
    }
    set<pair<int, int>> pq;
    vector<int> distance(graph.size(), INF);
    vector<bool> visited(graph.size(), false);
    pq.insert({0, 0});
    distance.at(0) = 0;
    while (!pq.empty())
    {
        int u = (*pq.begin()).second;
        pq.erase(pq.begin());
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        for (auto i : graph.at(u))
        {
            int v = i.second;
            int weight = i.first;
            if (visited[v] == false and distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                pq.insert({distance[v], v});
            }
        }
    }
    printi(distance.at(n - 1), '\n');
    return 0;
}