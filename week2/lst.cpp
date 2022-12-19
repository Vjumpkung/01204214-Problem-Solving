#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> l = {1, 2, 3, 5, 6, 4, 7};

    list<int>::iterator i = l.begin();

    cout << *i << "\n";

    return 0;
}