#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

void printi(int num, char end)
{
    if (num == -1)
    {
        putchar('-');
        putchar('1');
        putchar(end);
        return;
    }
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

set<pair<int, pair<int, int>>> edges;
int vertex, edge;

int find_set(int v, vector<int> &arr)
{
    if (v == arr[v])
    {
        return v;
    }
    return arr[v] = find_set(arr[v], arr);
}

void union_sets(int a, int b, vector<int> &arr)
{
    if (a != b)
    {
        arr[b] = a;
    }
}

void init_set(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int main()
{
    vertex = geti();
    edge = geti();
    vector<int> arr(vertex);
    for (int i = 0; i < edge; i++)
    {
        int f, t, w;
        f = geti();
        t = geti();
        w = geti();
        edges.insert({w, {f - 1, t - 1}});
        init_set(arr);
        int cost = 0;
        int union_count = 0;
        for (auto &i : edges)
        {
            if (union_count == vertex - 1)
            {
                break;
            }
            int a = find_set(i.second.first, arr);
            int b = find_set(i.second.second, arr);
            if (a != b)
            {
                union_sets(a, b, arr);
                union_count++;
                cost += i.first;
            }
        }
        for (int i = 0; i < vertex - 1; i++)
        {
            if (find_set(i, arr) == find_set(i + 1, arr))
            {
                continue;
            }
            else
            {
                cost = -1;
            }
        }
        printi(cost, '\n');
    }
    return 0;
}