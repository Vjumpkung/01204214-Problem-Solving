#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    int n, t;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            t = 0;
            for (int k = j; k <= i; k++)
            {
                t += arr[k];
            }
            if (t > 0)
            {
                s.insert(t);
            }
        }
    }
    cout << s.size();
    return 0;
}