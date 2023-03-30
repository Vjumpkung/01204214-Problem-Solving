#include <iostream>

using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

const int MAX_N = 0xfffffff;

int row, col;
int mat[30][30];
int matans[30][30];

int main()
{
    fastio;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
            matans[i][j] = mat[i][j];
        }
    }
    for (int i = 1; i < row - 1; i++)
    {
        for (int j = 1; j < col - 1; j++)
        {
            // north
            int current_row = i;
            int current_col = j;
            int temp_sum = 0;
            int min_sum = MAX_N;
            while (current_row >= 0 and current_col >= 0 and current_row < row and current_col < col)
            {
                temp_sum += mat[current_row][current_col];
                current_row--;
            }
            min_sum = min(min_sum, temp_sum);
            current_row = i;
            current_col = j;
            temp_sum = 0;
            while (current_row >= 0 and current_col >= 0 and current_row < row and current_col < col)
            {
                temp_sum += mat[current_row][current_col];
                current_row++;
            }
            min_sum = min(min_sum, temp_sum);
            current_row = i;
            current_col = j;
            temp_sum = 0;
            while (current_row >= 0 and current_col >= 0 and current_row < row and current_col < col)
            {
                temp_sum += mat[current_row][current_col];
                current_col++;
            }
            min_sum = min(min_sum, temp_sum);
            current_row = i;
            current_col = j;
            temp_sum = 0;
            while (current_row >= 0 and current_col >= 0 and current_row < row and current_col < col)
            {
                temp_sum += mat[current_row][current_col];
                current_col--;
            }
            min_sum = min(min_sum, temp_sum);
            matans[i][j] = min_sum;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
