#include <iostream>

using namespace std;

string str;
string sub;

int main()
{
    cin >> sub;
    cin >> str;
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < str.length())
    {
        if (str[i] == sub[j])
        {
            j++;
            if (j == sub.length())
            {
                count++;
                j = 0;
            }
        }
        i++;
    }
    cout << count << "\n";
    return 0;
}