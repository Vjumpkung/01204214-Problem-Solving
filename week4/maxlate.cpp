#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        int d, c;
        cin >> d >> c;
        vec.push_back({d, c});
    }
    sort(vec.begin(), vec.end());
    int total_time = 0;
    int cost = 0;
    for (auto &i : vec)
    {
        total_time += i.second;
        if (total_time - i.first > 10)
        {
            cost = max(cost, (total_time - i.first - 10) * 1000);
        }
    }
    cout << cost;
    return 0;
}