#include "probelib.h"
#include <cstdio>

int n;

int main()
{
    int n = probe_init();

    int low, mid, high;

    low = 0;
    high = n;

    while (1)
    {
        mid = (low + high) / 2;
        if (low == high)
        {
            break;
        }
        if (probe_check(low, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    probe_answer(mid);

    return 0;
}
