#include <iostream>
#include <list>

using namespace std;

int find_set(int v, int *arr)
{
    if (v == arr[v])
    {
        return v;
    }
    return arr[v] = find_set(arr[v], arr);
}

void union_sets(int a, int b, int *arr)
{
    a = find_set(a, arr);
    b = find_set(b, arr);
    if (a != b)
    {
        arr[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    int arr[n];
    list<int> v[n];
    for (int i = 0; i < n; i++)
    {
        v[i].push_back(i + 1);
        arr[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        union_sets(b - 1, a - 1, arr);
        list<int>::iterator it = v[find_set(b - 1, arr)].begin();
        while (it != v[arr[b - 1]].end())
        {
            if (*it == b)
            {
                break;
            }
            it++;
        }
        v[a - 1].splice(++it, v[a - 1]);
    }
    for (auto x : v[find_set(0, arr)])
    {
        cout << x << " ";
    }
    return 0;
}