#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

vector<int> arr(200);
int n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> D;
    D[0] = 0;
    for (auto &a : arr)
    {
        map<int, int> D2 = D;
        for (auto &i : D)
        {
            int d = i.first;
            int s = i.second;
            vector<int> t;
            int s2 = s + a;
            t.push_back(d - a);
            t.push_back(d + a);
            for (auto &d2 : t)
            {
                D2[abs(d2)] = max(D2[abs(d2)], s2);
            }
        }
        D = D2;
    }
    cout << (int)D[0] / 2 << "\n";
    return 0;
}