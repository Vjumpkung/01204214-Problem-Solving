#include "traffic.h"
#include <cmath>
#include <cstdio>

int main()
{
    int n, k;
    traffic_init(&n, &k);
    int x1, x2, y1, y2;
    int vertical_detect = 0;
    int horizontal_detect = 0;
    x1 = 1;
    x2 = n;
    y1 = 1;
    y2 = n;
    // vertical line
    for (int i = 1; i <= n; i++)
    {
        if (traffic_query(i, 1, i, n) > n - 1)
        {
            vertical_detect = 1;
            x1 = i;
            x2 = i;
            break;
        }
    }
    // horizontal line
    for (int i = 1; i <= n; i++)
    {
        if (traffic_query(1, i, n, i) > n - 1)
        {
            horizontal_detect = 1;
            y1 = i;
            y2 = i;
            break;
        }
    }
    if (vertical_detect)
    {
        int low = n;
        int high = 1;
        while (1)
        {
            int mid = (low + high) / 2;
            if (traffic_query(x1, mid - 1, x1, mid) == 2)
            {
                traffic_report(x1, mid - 1, x1, mid, 0, 0, 0, 0);
            }
            else if (traffic_query(x1, mid, x1, mid + 1) == 2)
            {
                traffic_report(x1, mid, x1, mid + 1, 0, 0, 0, 0);
            }
            else if (traffic_query(x1, low, x1, mid) > abs(low - mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    else
    {
        int low = n;
        int high = 1;
        while (1)
        {
            int mid = (low + high) / 2;
            if (traffic_query(mid - 1, y1, mid, y1) == 2)
            {
                traffic_report(mid - 1, y1, mid, y1, 0, 0, 0, 0);
            }
            else if (traffic_query(mid, y1, mid + 1, y1) == 2)
            {
                traffic_report(mid, y1, mid + 1, y1, 0, 0, 0, 0);
            }
            else if (traffic_query(low, y1, mid, y1) > abs(low - mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return 0;
}