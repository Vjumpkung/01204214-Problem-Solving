#include <iostream>
#include <stack>
using namespace std;

void s_clear(stack<int> &s)
{
    while (!s.empty())
    {
        s.pop();
    }
}

int main()
{
    stack<int> s, t, u;
    int n, q, o = 0;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        else
        {
            while (1)
            {
                o = 0;
                for (int i = 0; i < n; i++)
                {
                    cin >> q;
                    if (q == 0)
                    {
                        cout << endl;
                        o = 1;
                        s_clear(s);
                        s_clear(t);
                        s_clear(u);
                        break;
                    }

                    s.push(q);
                    t.push(i + 1);
                }

                if (o)
                {
                    break;
                }

                while (!s.empty() && !t.empty())
                {
                    if (!s.empty() && (s.top() == t.top()))
                    {
                        t.pop();
                        s.pop();
                    }
                    else if (!u.empty() && (u.top() == t.top()))
                    {
                        u.pop();
                        t.pop();
                    }
                    else
                    {
                        u.push(s.top());
                        s.pop();
                    }
                }

                while (!u.empty() && !t.empty())
                {
                    if (u.top() == t.top())
                    {
                        u.pop();
                        t.pop();
                    }
                    else
                    {
                        break;
                    }
                }

                if (!u.empty())
                {
                    cout << "No\n";
                }
                else
                {
                    cout << "Yes\n";
                }

                s_clear(s);
                s_clear(t);
                s_clear(u);
            }
        }
    }

    return 0;
}