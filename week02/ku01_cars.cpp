#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n, c = 0;
    cin >> n;
    int a, b;
    list<int> y;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        y.push_front(b);
    }

    int maxx = -1;

    for (auto &i : y)
    {
        if (i > maxx)
        {
            c++;
            maxx = i;
        }
    }

    cout << n - c;

    return 0;
}