#include <iostream>

using namespace std;

string finds;
string text;

int main()
{
    cin >> finds;
    cin >> text;
    int count = 0;
    int total = 0;
    for (auto i : text)
    {
        if (i == finds[count])
        {
            if (count == (int)(finds.length() - 1))
            {
                total++;
            }
            count = (count + 1) % (finds.length());
        }
    }
    cout << total << "\n";
    return 0;
}