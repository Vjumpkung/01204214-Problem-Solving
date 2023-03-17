#include <iostream>

using namespace std;

char arr[100][100];
bool tra[100][100] = {{false}};
int n, m;

bool walk(int r1, int r2, int c1, int c2)
{
    tra[r1][c1] = true;
    tra[r1][c2] = true;
    tra[r2][c1] = true;
    tra[r2][c2] = true;
    if (arr[r2][c1] == 'G' && arr[r2][c2] == 'G')
    {
        return true;
    }
    if (!(tra[r1 + 1][c1] && tra[r2 + 1][c1] && tra[r1 + 1][c2] && tra[r2 + 1][c2]) && r1 + 1 < n && r2 + 1 < n && (((arr[r1 + 1][c1] == '.') || (arr[r1 + 1][c1] == 'G')) && ((arr[r1 + 1][c2] == '.') || (arr[r1 + 1][c2] == 'G')) && ((arr[r2 + 1][c1] == '.') || (arr[r2 + 1][c1] == 'G')) && ((arr[r2 + 1][c2] == '.') || (arr[r2 + 1][c2] == 'G'))))
    {
        if (walk(r1 + 1, r2 + 1, c1, c2))
        {
            return true;
        }
    }
    if (!(tra[r1 - 1][c1] && tra[r2 - 1][c1] && tra[r1 - 1][c2] && tra[r2 - 1][c2]) && r1 - 1 >= 0 && r2 - 1 >= 0 && (((arr[r1 - 1][c1] == '.') || (arr[r1 - 1][c1] == 'G')) && ((arr[r1 - 1][c2] == '.') || (arr[r1 - 1][c2] == 'G')) && ((arr[r2 - 1][c1] == '.') || (arr[r2 - 1][c1] == 'G')) && ((arr[r2 - 1][c2] == '.') || (arr[r2 - 1][c2] == 'G'))))
    {
        if (walk(r1 - 1, r2 - 1, c1, c2))
        {
            return true;
        }
    }
    if (!(tra[r1][c1 + 1] && tra[r2][c1 + 1] && tra[r1][c2 + 1] && tra[r2][c2 + 1]) && c1 + 1 < m && c2 + 1 < m && (((arr[r1][c1 + 1] == '.') || (arr[r1][c1 + 1] == 'G')) && ((arr[r1][c2 + 1] == '.') || (arr[r1][c2 + 1] == 'G')) && ((arr[r2][c1 + 1] == '.') || (arr[r2][c1 + 1] == 'G')) && ((arr[r2][c2 + 1] == '.') || (arr[r2][c2 + 1] == 'G'))))
    {
        if (walk(r1, r2, c1 + 1, c2 + 1))
        {
            return true;
        }
    }
    if (!(tra[r1][c1 - 1] && tra[r2][c1 - 1] && tra[r1][c2 - 1] && tra[r2][c2 - 1]) && c1 - 1 >= 0 && c2 - 1 >= 0 && (((arr[r1][c1 - 1] == '.') || (arr[r1][c1 - 1] == 'G')) && ((arr[r1][c2 - 1] == '.') || (arr[r1][c2 - 1] == 'G')) && ((arr[r2][c1 - 1] == '.') || (arr[r2][c1 - 1] == 'G')) && ((arr[r2][c2 - 1] == '.') || (arr[r2][c2 - 1] == 'G'))))
    {
        if (walk(r1, r2, c1 - 1, c2 - 1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int k = 0; k < m; k++)
    {
        arr[n - 1][k] = 'G';
    }
    bool p = false;
    for (int i = 0; i < m - 1; i++)
    {
        if (arr[0][i] == '.' && arr[0][i + 1] == '.' && arr[1][i] == '.' && arr[0][i + 1] == '.' && walk(0, 1, i, i + 1))
        {
            p = p | true;
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                tra[j][k] = false;
            }
        }
    }
    if (p)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}