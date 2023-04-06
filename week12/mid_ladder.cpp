#include <iostream>
#include <vector>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

const int MAX_N = 1005;

int arr[MAX_N];
int n, m;
int current = 0;

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    current = 0;
    while (m--)
    {
        int x;
        cin >> x;
        current += x;
        current += arr[current];
        if (current >= n)
        {
            current = n;
        }
        if (current < 0)
        {
            current = 0;
        }
    }
    cout << current << endl;
    return 0;
}
