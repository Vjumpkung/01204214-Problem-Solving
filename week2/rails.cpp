#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main()
{
    int u, n, t;
    stack<int> s;
    list<int> l, a;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        else
        {
            bool e = false;
            while (1)
            {
                for (int i = 0; i < n; i++)
                {
                    cin >> t;
                    if (t == 0)
                    {
                        l.clear();
                        a.clear();
                        cout << "\n";
                        e = true;
                        while (!s.empty())
                        {
                            s.pop();
                        }
                        break;
                    }
                    a.push_back(t);
                    l.push_back(i + 1);
                }
                if (e)
                {
                    break;
                }
                list<int>::iterator it = a.begin();
                while (it != a.end() && !l.empty())
                {
                    if (l.front() == *it)
                    {
                        l.pop_front();
                        it++;
                    }
                    else if (!s.empty() && (s.top() == *it))
                    {
                        s.pop();
                        it++;
                    }
                    else
                    {
                        s.push(l.front());
                        l.pop_front();
                    }
                }
                while (it != a.end() && !s.empty())
                {
                    if (s.top() == *it)
                    {
                        s.pop();
                        it++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (!s.empty())
                {
                    cout << "No\n";
                }
                else
                {
                    cout << "Yes\n";
                }
                l.clear();
                a.clear();
                while (!s.empty())
                {
                    s.pop();
                }
            }
        }
    }
    return 0;
}