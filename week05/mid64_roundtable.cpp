#include <iostream>
#include <map>

using namespace std;

int arr[200001];
int same[200001];
map<int, int> m;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr[i] = t - 1;
        m[t - 1] = ((t - i - 1) % n + n) % n;
    }
    for (auto i : m)
    {
        same[i.second]++;
    }
    int maxx = -1;
    for (int i = 0; i < n; i++)
    {
        maxx = max(same[i], maxx);
    }
    cout << maxx << "\n";
    return 0;
}
