#include <iostream>
#include <vector>

using namespace std;

class CKKC
{
public:
    char lst[10000];
    int n;
    void get_input()
    {
        cin >> n;
        int t = 1;
        while (t != 0)
        {
            cin >> t;
            lst[t] = 'X';
        }
    }
    char show_answer()
    {
        string ck = "KC";
        int counter = 0;
        lst[2558] = ck[counter];
        for (int i = 2558; i <= 3000; i++)
        {
            if (lst[i] == 'X' || lst[i] == 'K' || lst[i] == 'C')
            {
                continue;
            }
            else
            {
                counter = (counter + 1) % 2;
                lst[i] = ck[counter];
            }
        }
        return lst[n];
    }
};

int main()
{
    CKKC c;
    c.get_input();
    cout << c.show_answer() << "\n";
    return 0;
}