#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int m;
    int mode = 0;
    cin >> s;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N')
        {
            m = 0;
        }
        else if (s[i] == 'E')
        {
            m = 1;
        }
        else if (s[i] == 'S')
        {
            m = 2;
        }
        else if (s[i] == 'W')
        {
            m = 3;
        }
        else if (s[i] == 'Z')
        {
            cout << "Z";
            mode = 0;
            continue;
        }
        while (mode != m)
        {
            cout << "R";
            mode = (mode + 1) % 4;
        }
        cout << "F";
    }
    return 0;
}