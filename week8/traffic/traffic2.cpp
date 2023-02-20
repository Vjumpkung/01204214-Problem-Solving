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
    int ans1x1 = 0, ans1y1 = 0, ans1x2 = 0, ans1y2 = 0;
    int ans2x1 = 0, ans2y1 = 0, ans2x2 = 0, ans2y2 = 0;
    if (vertical_detect)
    {
        int low = n;
        int high = 1;
        while (1)
        {
            int mid = (low + high) / 2;
            if (traffic_query(x1, mid - 1, x1, mid) == 2)
            {
                ans1x1 = x1;
                ans1y1 = mid - 1;
                ans1x2 = x1;
                ans1y2 = mid;
                break;
            }
            else if (traffic_query(x1, mid, x1, mid + 1) == 2)
            {
                ans1x1 = x1;
                ans1y1 = mid;
                ans1x2 = x1;
                ans1y2 = mid + 1;
                break;
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
    if (horizontal_detect)
    {
        int low = n;
        int high = 1;
        while (1)
        {
            int mid = (low + high) / 2;
            if (traffic_query(mid - 1, y1, mid, y1) == 2)
            {
                ans2x1 = mid - 1;
                ans2y1 = y1;
                ans2x2 = mid;
                ans2y2 = y1;
                break;
            }
            else if (traffic_query(mid, y1, mid + 1, y1) == 2)
            {
                ans2x1 = mid;
                ans2y1 = y1;
                ans2x2 = mid + 1;
                ans2y2 = y1;
                break;
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
    if (k == 1)
    {
        if (vertical_detect)
            traffic_report(ans1x1, ans1y1, ans1x2, ans1y2, 0, 0, 0, 0);
        else if (horizontal_detect)
            traffic_report(ans2x1, ans2y1, ans2x2, ans2y2, 0, 0, 0, 0);
    }
    else
    {
        traffic_report(ans1x1, ans1y1, ans1x2, ans1y2, ans2x1, ans2y1, ans2x2, ans2y2);
    }
    return 0;
}