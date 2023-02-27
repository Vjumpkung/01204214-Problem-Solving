#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, n, k;
    vector<pair<int, int>> a;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            int x, y;
            cin >> x >> y;
            a.push_back(make_pair(x, y));
        }
    }
    return 0;
}