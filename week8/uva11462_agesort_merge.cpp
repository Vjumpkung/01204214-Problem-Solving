#include <iostream>

using namespace std;

short arr[2000000];
short l[1000000], r[1000000];

void printi(int num)
{
    int i = num;
    int t;
    char cx;
    int a = 0;
    char temp[3];
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

void Merge(int start, int middle, int end)
{
    int l_size = middle - start + 1, r_size = end - middle;
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
}

void MergeSort(int start, int end)
{
    int size = end - start + 1;
    int middle;
    if (size > 1)
    {
        middle = (start + end) / 2;
        MergeSort(start, middle);
        MergeSort(middle + 1, end);
        Merge(start, middle, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        MergeSort(0, n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            printi(arr[i]);
            putchar(' ');
        }
        printi(arr[n - 1]);
        putchar('\n');
    }
    return 0;
}