#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n;
    list<int> l, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        l.push_back(t);
        v.push_back(i + 1);
    }
    int max_sequence = 0;
    for (int j = 0; j < n; j++)
    {
        int count = 0;
        int temp = l.back();
        l.pop_back();
        l.push_front(temp);
        auto s = v.begin();
        for (auto i : l)
        {
            if (i == *s)
            {
                count++;
            }
            s++;
        }
        max_sequence = max(count, max_sequence);
    }
    cout << max_sequence << endl;
    return 0;
}
