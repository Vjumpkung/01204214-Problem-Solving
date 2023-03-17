#include <iostream>

using namespace std;

typedef long long int lld;

lld merge(lld *arr, int start, int middle, int end)
{
    int l_size = middle - start + 1, r_size = end - middle;
    lld l[l_size], r[r_size];
    int u = 0;
    for (int i = start; i <= middle; i++)
    {
        l[u] = arr[i];
        u++;
    }
    int v = 0;
    for (int j = middle + 1; j <= end; j++)
    {
        r[v] = arr[j];
        v++;
    }
    int a = 0, b = 0, c = start;
    lld count = 0;
    while (a < l_size && b < r_size)
    {
        if (l[a] <= r[b])
        {
            arr[c] = l[a];
            a++;
        }
        else
        {
            arr[c] = r[b];
            b++;
            count += l_size - a;
        }
        c++;
    }
    for (int ll = a; ll < l_size; ll++)
    {
        arr[c] = l[ll];
        c++;
    }
    for (int rr = b; rr < r_size; rr++)
    {
        arr[c] = r[rr];
        c++;
    }
    return count;
}

lld merge_sort(lld *arr, int start, int end)
{
    int size = end - start + 1;
    int middle;
    lld count = 0;
    for (int i = 1; i <= size; i *= 2)
    {
        for (int j = start; j < end; j += 2 * i)
        {
            middle = j + i - 1;
            if (middle < end)
            {
                count += merge(arr, j, middle, min(end, j + 2 * i - 1));
            }
        }
    }
    return count;
}

int main()
{
    lld n;
    cin >> n;
    lld a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    cout << merge_sort(a, 0, n - 1) << endl;
    return 0;
}