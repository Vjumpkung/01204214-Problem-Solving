#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int coord[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
int mat[21][21];
int visited[21][21];
int n, power;

int main()
{
    cin >> n >> power;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            visited[i][j] = 0;
        }
    }
    queue<pair<int, int>> q;
    int row = 0, col = 0;
    q.push({0, 0});
    while (not q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        if (row == n - 1 and col == n - 1)
        {
            break;
        }
        q.pop();
        visited[row][col] = 1;
        for (int j = 0; j < 4; j++)
        {
            if (row + coord[0][j] < n and col + coord[1][j] < n and row + coord[0][j] >= 0 and col + coord[1][j] >= 0)
            {
                if (not visited[row + coord[0][j]][col + coord[1][j]])
                {
                    if (mat[row][col] >= mat[row + coord[0][j]][col + coord[1][j]])
                    {
                        visited[row + coord[0][j]][col + coord[1][j]] = 1;
                        q.push({row + coord[0][j], col + coord[1][j]});
                    }
                    else if (mat[row + coord[0][j]][col + coord[1][j]] - mat[row][col] <= power)
                    {
                        visited[row + coord[0][j]][col + coord[1][j]] = 1;
                        q.push({row + coord[0][j], col + coord[1][j]});
                    }
                }
            }
        }
    }
    if (row == n - 1 and col == n - 1)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}