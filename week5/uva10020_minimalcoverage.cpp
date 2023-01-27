#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        vector<pair<int, int>> coord(1);
        while (1)
        {
            cin >> coord.at(0).first >> coord.at(0).second;
            if (coord.at(0).first == 0 and coord.at(0).second == 0)
            {
                break;
            }
            else
            {
                coord.push_back({coord.at(0).first, coord.at(0).second});
            }
        }
        sort(coord.begin() + 1, coord.end());
        int cur_l = 0, reach = 0;
        unsigned int i = 1;
        vector<pair<int, int>> segments;
        while (reach < m)
        {
            int newLeft = cur_l;
            unsigned int far = 0;
            for (; i < coord.size(); i++)
            {
                if (coord.at(i).first > cur_l)
                {
                    break;
                }
                else if (coord.at(i).second >= newLeft)
                {
                    newLeft = coord.at(i).second;
                    far = i;
                }
            }
            if (far == 0)
            {
                break;
            }
            segments.push_back(coord.at(far));
            cur_l = reach = newLeft;
        }
        if (reach >= m)
        {
            cout << segments.size() << "\n";
            for (auto i : segments)
            {
                cout << i.first << " " << i.second << "\n";
            }
        }
        else
        {
            cout << 0 << "\n";
        }
        if (n)
        {
            cout << "\n";
        }
    }
    return 0;
}