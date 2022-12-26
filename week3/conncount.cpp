#include <iostream>
#include <set>

using namespace std;

int c = 0;

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
    int n, m;
    int t, u;
    cin >> n >> m;
    int arr[n] = {0};
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t >> u;
        union_sets(t - 1, u - 1, arr);
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(find_set(i, arr));
    }
    cout << s.size();
    return 0;
}