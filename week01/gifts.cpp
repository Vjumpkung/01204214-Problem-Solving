#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, maxx = 0;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    for (uint i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) >= 0)
        {
            maxx += vec.at(i);
        }
    }
    cout << maxx;
    return 0;
}