#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> vec2;

int main()
{
    int n, m, minn = 0xfffffff;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (minn > t)
        {
            minn = t;
        }
        vec.emplace_back(minn);
        vec2.emplace_back(minn);
    }
    reverse(vec2.begin(), vec2.end());
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            b--;
            cout << vec[b] << endl;
        }
        else
        {
            cout << n - (lower_bound(vec2.begin(), vec2.end(), b) - vec2.begin()) << endl;
        }
    }
    return 0;
}