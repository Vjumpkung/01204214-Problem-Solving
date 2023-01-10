#include <iostream>

using namespace std;

char Graph[21][21];
bool visit[21][21] = {0};
int N, Q;
int sr, sc, dr, dc;

int dfs(int row, int col, int use_door)
{
    visit[row][col] = 1;
    if (row == dr and col == dc)
    {
        return 1;
    }
    if (row + 1 < N and not visit[row + 1][col] and Graph[row + 1][col] == '.')
    {
        if (dfs(row + 1, col, use_door))
        {
            return 1;
        }
    }
    if (use_door == 0 and row + 1 < N and not visit[row + 1][col] and Graph[row + 1][col] == 'O')
    {
        use_door = 1;
        if (dfs(row + 1, col, use_door))
        {
            return 1;
        }
        use_door = 0;
    }
    if (row - 1 >= 0 and not visit[row - 1][col] and Graph[row - 1][col] == '.')
    {
        if (dfs(row - 1, col, use_door))
        {
            return 1;
        }
    }
    if (use_door == 0 and row - 1 >= 0 and not visit[row - 1][col] and Graph[row - 1][col] == 'O')
    {
        use_door = 1;
        if (dfs(row - 1, col, use_door))
        {
            return 1;
        }
        use_door = 0;
    }
    if (col + 1 < N and not visit[row][col + 1] and Graph[row][col + 1] == '.')
    {
        if (dfs(row, col + 1, use_door))
        {
            return 1;
        }
    }
    if (use_door == 0 and col + 1 < N and not visit[row][col + 1] and Graph[row][col + 1] == 'O')
    {
        use_door = 1;
        if (dfs(row, col + 1, use_door))
        {
            return 1;
        }
        use_door = 0;
    }
    if (col - 1 >= 0 and not visit[row][col - 1] and Graph[row][col - 1] == '.')
    {
        if (dfs(row, col - 1, use_door))
        {
            return 1;
        }
    }
    if (use_door == 0 and col - 1 >= 0 and not visit[row][col - 1] and Graph[row][col - 1] == 'O')
    {
        use_door = 1;
        if (dfs(row, col - 1, use_door))
        {
            return 1;
        }
        use_door = 0;
    }
    return 0;
}

int main()
{
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Graph[i][j];
        }
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> sr >> sc >> dr >> dc;
        sr--;
        sc--;
        dr--;
        dc--;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visit[i][j] = 0;
            }
        }
        if (dfs(sr, sc, 0))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}