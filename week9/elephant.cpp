#include <iostream>

using namespace std;

int arr[100000];
int dpi[100000] = {-1};
int n;

int jump(int idx)
{
    if (idx + 2 < n)
    {
        if (dpi[idx] == -1)
        {
            dpi[idx] = max(jump(idx + 1), jump(idx + 3) + arr[idx + 2]);
        }
        return dpi[idx];
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dpi[i] = -1;
        cin >> arr[i];
    }
    cout << jump(0) << endl;
    return 0;
}
