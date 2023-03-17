#include <iostream>
#include <queue>
#include <utility>
#define INF 0xfffffff

using namespace std;

int mat[31][31];
int visited[31][31];
int dist[31][31];
int coord[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};

int main()
{
    int r, c, a, b, x, y;
    cin >> r >> c >> a >> b >> x >> y;
    a--;
    b--;
    x--;
    y--;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
            visited[i][j] = 0;
            dist[i][j] = INF;
        }
    }
    queue<pair<int, int>> q;
    queue<int> d;
    q.push({a, b});
    d.push(0);
    dist[a][b] = 0;
    while (not q.empty() and not d.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        int dis = d.front();
        q.pop();
        visited[row][col] = 1;
        for (int j = 0; j < 4; j++)
        {
            if (row + coord[0][j] < r and row + coord[0][j] >= 0 and col + coord[1][j] < c and col + coord[1][j] >= 0)
            {
                if (mat[row][col] == mat[row + coord[0][j]][col + coord[1][j]])
                {
                    if (dist[row + coord[0][j]][col + coord[1][j]] > dist[row][col] + dis)
                    {
                        dist[row + coord[0][j]][col + coord[1][j]] = dist[row][col] + dis;
                        q.push({row + coord[0][j], col + coord[1][j]});
                        d.push(dis);
                    }
                }
                else
                {
                    if (dist[row + coord[0][j]][col + coord[1][j]] > dist[row][col] + dis + 1)
                    {
                        dist[row + coord[0][j]][col + coord[1][j]] = dist[row][col] + dis + 1;
                        q.push({row + coord[0][j], col + coord[1][j]});
                        d.push(dis + 1);
                    }
                }
            }
        }
    }
    cout << dist[x][y] << "\n";
    return 0;
}