#include "traffic.h"
#include <cmath>
#include <cstdio>
#include <vector>

int n, k;
int vertical_detect = 0;
int horizontal_detect = 0;
int answer[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};
int low, high, mid, total, ansCount = 0, temp;

using namespace std;

void vertical(int i, int low, int high, int total)
{
    int mid = floor(abs(high + low) / 2);
    if (abs(low - high) == 1 and total == 2)
    {
        for (int j = 0; j < ansCount; j++)
        {
            if (answer[j][0] == i and answer[j][1] == low and answer[j][2] == i and answer[j][3] == high)
            {
                return;
            }
        }
        answer[ansCount][0] = i;
        answer[ansCount][1] = low;
        answer[ansCount][2] = i;
        answer[ansCount][3] = high;
        ansCount++;
    }
    else if (total <= abs(low - high))
    {
        return;
    }
    else
    {
        int temp = traffic_query(i, low, i, mid);
        if (temp > abs(low - mid))
        {
            vertical(i, low, mid, temp);
        }
        if (total - temp > abs(mid - high))
        {
            vertical(i, mid, high, total - temp);
        }
    }
}

void horizontal(int i, int low, int high, int total)
{
    int mid = floor(abs(high + low) / 2);
    if (abs(low - high) == 1 and total == 2)
    {
        for (int j = 0; j < ansCount; j++)
        {
            if (answer[j][0] == low and answer[j][1] == i and answer[j][2] == high and answer[j][3] == i)
            {
                return;
            }
        }
        answer[ansCount][0] = low;
        answer[ansCount][1] = i;
        answer[ansCount][2] = high;
        answer[ansCount][3] = i;
        ansCount++;
    }
    else if (total <= abs(low - high))
    {
        return;
    }
    else
    {
        int temp = traffic_query(low, i, mid, i);
        if (temp > abs(low - mid))
        {
            horizontal(i, low, mid, temp);
        }
        if (total - temp > abs(mid - high))
        {
            horizontal(i, mid, high, total - temp);
        }
    }
}

int main()
{
    traffic_init(&n, &k);
    // vertical line
    for (int i = 1; i <= n; i++)
    {
        total = traffic_query(i, 1, i, n);
        low = 1;
        high = n;
        if (total > n - 1)
        {
            vertical(i, low, high, total);
        }
    }
    // horizontal line
    for (int i = 1; i <= n; i++)
    {
        total = traffic_query(1, i, n, i);
        low = 1;
        high = n;
        if (total > n - 1)
        {
            horizontal(i, low, high, total);
        }
    }

    traffic_report(answer[0][0], answer[0][1], answer[0][2], answer[0][3], answer[1][0], answer[1][1], answer[1][2], answer[1][3]);

    return 0;
}