#include <iostream>
#include <list>

using namespace std;

class Virus
{
public:
    list<int> lst;
    list<int>::iterator it;
    void init()
    {
        it = lst.begin();
    }
    void insertBefore(int n)
    {
        lst.insert(it, n);
    }
    void insertAfter(int n)
    {
        it++;
        lst.insert(it, n);
        it--;
        it--;
    }
    void reset()
    {
        it = lst.begin();
    }
    void next()
    {
        it++;
        if (it == lst.end())
        {
            it = lst.begin();
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    Virus virus;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        virus.lst.push_back(t);
    }
    int x;
    virus.init();
    while (q--)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
            virus.reset();
            break;

        case 2:
            virus.next();
            break;
        case 3:

            cin >> x;
            virus.insertBefore(x);
            break;
        case 4:
            cin >> x;
            virus.insertAfter(x);
            break;
        }
    }
    for (auto &i : virus.lst)
    {
        cout << i << "\n";
    }
    return 0;
}
