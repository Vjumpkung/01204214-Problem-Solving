#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N')
        {
            y++;
        }
        else if (s[i] == 'S')
        {
            y--;
        }
        else if (s[i] == 'E')
        {
            x++;
        }
        else if (s[i] == 'W')
        {
            x--;
        }
        else if (s[i] == 'Z')
        {
            x = 0;
            y = 0;
        }
    }
    cout << x << " " << y;
    return 0;
}