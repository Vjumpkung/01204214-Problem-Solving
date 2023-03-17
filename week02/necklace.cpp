#include <cstdio>
#include <list>

using namespace std;

const int MAX_N = 300000;

int n, a, b;
int arr[MAX_N];
list<int> v[MAX_N];

void printi(int num)
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
    n = geti();
    for (int i = 0; i < n; i++)
    {
        v[i].push_back(i + 1);
        arr[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        a = geti();
        b = geti();
        union_sets(b - 1, a - 1, arr);
        auto it = v[find_set(b - 1, arr)].begin();
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
        printi(x);
        putchar(' ');
    }
    return 0;
}