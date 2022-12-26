#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector<pair<int, int>> comp;
    cin >> n;
    int x = 1;
    for (int i = 0; i < 4; i++)
    {
        int maxx = -1;
        int maxidx = i;
        for (int j = 0; j < n; j++)
        {
            cin >> m;
            if (m > maxx)
            {
                maxx = m;
                maxidx = x;
            }
            x++;
        }
        comp.push_back({maxidx, maxx});
    }
    pair<int, int> A = comp[0].second > comp[1].second ? comp[0] : comp[1];
    pair<int, int> B = comp[2].second > comp[3].second ? comp[2] : comp[3];
    pair<int, int> F = A.second > B.second ? A : B;
    pair<int, int> S = A.second > B.second ? B : A;
    A = comp[0].second > comp[1].second ? comp[1] : comp[0];
    B = comp[2].second > comp[3].second ? comp[3] : comp[2];
    cout << F.first << " ";
    cout << S.first << " ";
    cout << A.first << " ";
    cout << B.first;
    return 0;
}