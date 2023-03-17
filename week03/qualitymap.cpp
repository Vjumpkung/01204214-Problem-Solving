#include <iostream>

using namespace std;

char arr[100][100];
bool tra[100][100] = {{false}};
int n, m;

int mode2 = 0;
int count = 0;

void travel(int row, int col, char start)
{
    if (tra[row][col])
    {
        return;
    }
    tra[row][col] = true;
    count++;
    if ((arr[row][col] == '$' or arr[row][col] == '*') and (arr[row][col] != start))
    {
        mode2 = 1;
    }
    if (!tra[row + 1][col] and (row + 1 < n) and (arr[row + 1][col] != '#'))
    {
        travel(row + 1, col, start);
    }
    if (!tra[row - 1][col] and (row - 1 >= 0) and (arr[row - 1][col] != '#'))
    {
        travel(row - 1, col, start);
    }
    if (!tra[row][col + 1] and (col + 1 < m) and (arr[row][col + 1] != '#'))
    {
        travel(row, col + 1, start);
    }
    if (!tra[row][col - 1] and (col - 1 >= 0) and (arr[row][col - 1] != '#'))
    {
        travel(row, col - 1, start);
    }
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
    int m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '*' or arr[i][j] == '$')
            {
                travel(i, j, arr[i][j]);
                if (mode2)
                {
                    m1 += count;
                }
                else
                {
                    m2 += count;
                }
                count = 0;
                mode2 = 0;
            }
        }
    }
    cout << m1 << " " << m2;
    return 0;
}