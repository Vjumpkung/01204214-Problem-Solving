#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool cmp(pair<double, double> &a, pair<double, double> &b)
{
    return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
}

int main()
{
    int round = 1;
    while (1)
    {
        vector<pair<double, double>> v;
        int n, d;
        int count = 0;
        int valid = 1;
        cin >> n >> d;
        if (n == 0 and d == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y > d)
            {
                valid = 0;
            }
            else
            {
                double A = x - sqrt(d * d - y * y);
                double B = x + sqrt(d * d - y * y);
                v.push_back({A, B});
            }
        }
        if (valid)
        {
            sort(v.begin(), v.end(), cmp);
            for (int i = 0; i < n; i = i)
            {
                int j = 0;
                for (j = 0; j < n; j++)
                {
                    if (v[j].first > v[i].second)
                    {
                        break;
                    }
                }
                i = j;
                count++;
            }
            cout << "Case " << round << ": " << count << endl;
        }
        else
        {
            cout << "Case " << round << ": -1\n";
        }
        round++;
    }
    return 0;
}