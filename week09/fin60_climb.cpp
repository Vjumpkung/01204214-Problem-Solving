#include <iostream>
#include <queue>

using namespace std;

char mapping[31][31];
int visited[31][31] = {{false}};
int r, c;

void bfs(int row, int col)
{
    int distance[31][31];
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            distance[i][j] = 0xffffff;
        }
    }
    distance[row][col] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if (x - 1 >= 0 && mapping[x - 1][y] == '.')
        {
            if (distance[x - 1][y] > distance[x][y] + 5)
            {
                distance[x - 1][y] = distance[x][y] + 5;
                q.push(make_pair(x - 1, y));
            }
        }
        if (x + 1 < r && mapping[x + 1][y] == '.')
        {
            if (distance[x + 1][y] > distance[x][y] + 0)
            {
                distance[x + 1][y] = distance[x][y] + 0;
                q.push(make_pair(x + 1, y));
            }
        }
        if (y - 1 >= 0 && mapping[x][y - 1] == '.')
        {
            if (distance[x][y - 1] > distance[x][y] + 1)
            {
                distance[x][y - 1] = distance[x][y] + 1;
                q.push(make_pair(x, y - 1));
            }
        }
        if (y + 1 < c && mapping[x][y + 1] == '.')
        {
            if (distance[x][y + 1] > distance[x][y] + 1)
            {
                distance[x][y + 1] = distance[x][y] + 1;
                q.push(make_pair(x, y + 1));
            }
        }
    }
    if (distance[0][c - 1] != 0xffffff)
        cout << distance[0][c - 1] << "\n";
    else
        cout << -1 << "\n";
}

int main()
{
    int row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mapping[i][j];
        }
    }
    r = row;
    c = col;
    bfs(row - 1, 0);
    return 0;
}