#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF 0xfffffff
using namespace std;

int r, c;
int r1, c1, r2, c2;
char graph[100][100];
int visited[100][100];
int dist[100][100];
int minDis[100][100];
int coord[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
vector<pair<int, int>> vec;
queue<pair<int, int>> q;

int main()
{
    cin >> r >> c;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];
            visited[i][j] = 0;
            dist[i][j] = 0;
            minDis[i][j] = INF;
            if (graph[i][j] == '*')
            {
                vec.push_back({i, j});
                vec.push_back({i, j});
            }
        }
    }
    int mode = 0;
    for (auto &i : vec)
    {
        for (int k = 0; k < r; k++)
        {
            for (int j = 0; j < c; j++)
            {
                visited[k][j] = 0;
                dist[k][j] = 0;
            }
        }
        if (mode == 0 and graph[i.first - 1][i.second] == '.' and graph[i.first + 1][i.second] == '.')
        {
            graph[i.first][i.second] = '.';
        }
        else if (mode == 1 and graph[i.first][i.second + 1] == '.' and graph[i.first][i.second - 1] == '.')
        {
            graph[i.first][i.second] = '.';
        }
        q.push({r1, c1});
        while (not q.empty())
        {
            int cr, cc;
            cr = q.front().first;
            cc = q.front().second;
            visited[cr][cc] = 1;
            q.pop();
            if (cr == r2 and cc == c2)
            {
                break;
            }
            for (int j = 0; j < 4; j++)
            {
                if (graph[cr + coord[0][j]][cc + coord[1][j]] == '.' and not visited[cr + coord[0][j]][cc + coord[1][j]])
                {
                    dist[cr + coord[0][j]][cc + coord[1][j]] = dist[cr][cc] + 1;
                    visited[cr + coord[0][j]][cc + coord[1][j]] = 1;
                    q.push({cr + coord[0][j], cc + coord[1][j]});
                }
            }
        }
        if (minDis[r2][c2] > dist[r2][c2] and dist[r2][c2] > 0)
        {
            minDis[r2][c2] = dist[r2][c2];
        }
        graph[i.first][i.second] = '*';
        mode = (mode + 1) % 2;
    }
    if (minDis[r2][c2] == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << minDis[r2][c2] << "\n";
    }
    return 0;
}