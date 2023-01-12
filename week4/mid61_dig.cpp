#include <iostream>
#include <queue>
#define INF 0xfffffff
using namespace std;

int r, c;
int r1, c1, r2, c2;
char graph[100][100];
int visited[2][100][100];
int dist[2][100][100];
struct point
{
    int current_row;
    int current_col;
    int distance;
    int dig;
};
queue<point> q;

void bfs()
{
    q.push({r1, c1, 0, 0});
    while (not q.empty())
    {
        int current_row, current_col, isDig, distance;
        current_row = q.front().current_row;
        current_col = q.front().current_col;
        isDig = q.front().dig;
        distance = q.front().distance;
        q.pop();
        if (isDig)
        {
            visited[1][current_row][current_col] = 1;
            if (dist[1][current_row][current_col] > distance)
            {
                dist[1][current_row][current_col] = distance;
            }
        }
        else
        {
            visited[0][current_row][current_col] = 1;
            if (dist[0][current_row][current_col] > distance)
            {
                dist[0][current_row][current_col] = distance;
            }
        }
        if (current_row == r2 and current_col == c2)
        {
            break;
        }
        if (isDig == 0 and current_row + 2 < r and (not visited[0][current_row + 1][current_col]) and graph[current_row + 1][current_col] == '*' and graph[current_row + 2][current_col] == '.')
        {
            q.push({current_row + 1, current_col, distance + 1, 1});
        }
        if (current_row + 1 < r and (not visited[isDig][current_row + 1][current_col]) and graph[current_row + 1][current_col] == '.')
        {
            q.push({current_row + 1, current_col, distance + 1, isDig});
        }
        if (isDig == 0 and current_row - 2 >= 0 and (not visited[0][current_row - 1][current_col]) and graph[current_row - 1][current_col] == '*' and graph[current_row - 2][current_col] == '.')
        {
            q.push({current_row - 1, current_col, distance + 1, 1});
        }
        if (current_row - 1 >= 0 and (not visited[isDig][current_row - 1][current_col]) and graph[current_row - 1][current_col] == '.')
        {
            q.push({current_row - 1, current_col, distance + 1, isDig});
        }
        if (isDig == 0 and current_col + 2 < c and (not visited[0][current_row][current_col + 1]) and graph[current_row][current_col + 1] == '*' and graph[current_row][current_col + 2] == '.')
        {
            q.push({current_row, current_col + 1, distance + 1, 1});
        }
        if (current_col + 1 < c and (not visited[isDig][current_row][current_col + 1]) and graph[current_row][current_col + 1] == '.')
        {
            q.push({current_row, current_col + 1, distance + 1, isDig});
        }
        if (isDig == 0 and current_col - 2 >= 0 and (not visited[0][current_row][current_col - 1]) and graph[current_row][current_col - 1] == '*' and graph[current_row][current_col - 2] == '.')
        {
            q.push({current_row, current_col - 1, distance + 1, 1});
        }
        if (current_col - 1 >= 0 and (not visited[isDig][current_row][current_col - 1]) and graph[current_row][current_col - 1] == '.')
        {
            q.push({current_row, current_col - 1, distance + 1, isDig});
        }
    }
    int da = dist[0][r2][c2];
    int db = dist[1][r2][c2];
    if (da == INF and db == INF)
    {
        cout << -1;
    }
    else
    {
        cout << (da > db ? db : da);
    }
    cout << endl;
}

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
            visited[0][i][j] = 0;
            visited[1][i][j] = 0;
            dist[0][i][j] = INF;
            dist[1][i][j] = INF;
        }
    }
    bfs();
    return 0;
}