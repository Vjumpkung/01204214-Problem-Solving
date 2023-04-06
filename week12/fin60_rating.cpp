#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int maxx = -1;
int maxx_num = 100001;
int count[100001];

int main()
{
    for (int i = 0; i < 100001; i++)
    {
        count[i] = 1;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 6; j > 0; j--)
        {
            if (i - j < 0)
            {
                continue;
            }
            if (v[i - j] == v[i])
            {
                count[i] = count[i - j] + 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (count[i] > maxx)
        {
            maxx = count[i];
            maxx_num = v[i];
        }
        else if (count[i] == maxx)
        {
            if (v[i] < maxx_num)
            {
                maxx_num = v[i];
            }
        }
    }
    cout << maxx_num << " " << maxx << "\n";
    return 0;
}