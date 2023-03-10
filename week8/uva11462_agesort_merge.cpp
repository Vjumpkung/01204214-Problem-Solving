#include <stdio.h>
#include <string.h>

int i, t, j, k, a;
int minn;
short arr[2000000];
short l[1000000], r[1000000];

void printi(int num, char end)
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
    for (int i = 1; i <= size; i *= 2)
    {
        for (int j = start; j < end; j += 2 * i)
        {
            middle = j + i - 1;
            if (middle < end)
            {
                minn = j + 2 * i - 1 < end ? j + 2 * i - 1 : end;
                Merge(j, middle, minn);
            }
        }
    }
}

int main()
{
    while (1)
    {
        i = geti();
        if (i == 0)
        {
            break;
        }
        else
        {
            a = -1;
            for (j = 0; j < i; j++)
            {
                t = geti();
                arr[j] = t;
            }
            MergeSort(0, i - 1);
            for (j = 0; j < i; j++)
            {
                if (j >= 0 && j < i - 1)
                {
                    printi(arr[j], ' ');
                }
                else if (j == i - 1)
                {
                    printi(arr[j], '\n');
                }
            }
        }
    }
    return 0;
}