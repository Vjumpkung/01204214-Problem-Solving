#include <iostream>

using namespace std;

int main()
{
    int coord[4] = {0, 0, 0, 0};
    string s;
    int k;
    cin >> s;
    cin >> k;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N')
        {
            coord[0]++;
        }
        else if (s[i] == 'S')
        {
            coord[1]++;
        }
        else if (s[i] == 'E')
        {
            coord[2]++;
        }
        else if (s[i] == 'W')
        {
            coord[3]++;
        }
    }
    if (coord[0] < coord[1])
    {
        swap(coord[0], coord[1]);
    }
    if (coord[2] < coord[3])
    {
        swap(coord[2], coord[3]);
    }
    while (k != 0)
    {
        if (coord[1] != 0)
        {
            coord[1]--;
            k--;
        }
        else if (coord[3] != 0)
        {
            coord[3]--;
            k--;
        }
        else if (coord[2] != 0)
        {
            coord[2]--;
            k--;
        }
        else if (coord[0] != 0)
        {
            coord[0]--;
            k--;
        }
    }
    cout << (coord[0] + coord[2] - coord[1] - coord[3]) * 2;
    return 0;
}
