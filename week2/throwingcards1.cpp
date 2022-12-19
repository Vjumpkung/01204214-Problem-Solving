#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int m = -1, t;
    queue<int> q, a;
    while (true)
    {
        cin >> m;
        if (m == 0)
        {
            break;
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                q.push(i + 1);
            }
            while (q.size() != 1)
            {
                t = q.front();
                a.push(t);
                q.pop();
                t = q.front();
                q.pop();
                q.push(t);
            }
            cout << "Discarded cards:";
            if (a.empty())
            {
                cout << "\n";
            }
            else
            {
                cout << " ";
            }
            while (!a.empty())
            {
                if (a.size() > 1)
                {
                    cout << a.front() << ", ";
                }
                else
                {
                    cout << a.front() << "\n";
                }
                a.pop();
            }
            cout << "Remaining card: " << q.front() << "\n";
            q.pop();
        }
    }
    return 0;
}