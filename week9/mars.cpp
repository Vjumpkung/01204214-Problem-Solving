#include <iostream>

using namespace std;

string words[10];

int d[1001][26][26];

int check(int a, int b)
{
    return min(abs(a - b), 26 - abs(a - b));
}

int main()
{
    int n, minDrop;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    for (int j = 0; j < n; j++)
    {
        minDrop = 0xffffff;
        for (int i = 0; i < words[j].length(); i++)
        {
            for (int k = 0; k < 26; k++)
            {
                for (int l = 0; l < 26; l++)
                {
                    d[i][k][l] = 0xffffff;
                }
            }
        }

        d[0][words[j][0] - 'A'][0] = check(words[j][0] - 'A', 0);
        d[0][0][words[j][0] - 'A'] = check(words[j][0] - 'A', 0);

        if (words[j].length() == 1)
        {
            cout << d[0][words[j][0] - 'A'][0] << endl;
            continue;
        }

        for (int i = 1; i < words[j].length(); i++)
        {
            for (int k = 0; k < 26; k++)
            {
                for (int l = 0; l < 26; l++)
                {
                    if (d[i - 1][k][l] == 0xffffff)
                    {
                        continue;
                    }
                    int a = check(words[j][i] - 'A', k);
                    d[i][words[j][i] - 'A'][l] = min(d[i - 1][k][l] + a, d[i][words[j][i] - 'A'][l]);
                    int b = check(words[j][i] - 'A', l);
                    d[i][k][words[j][i] - 'A'] = min(d[i - 1][k][l] + b, d[i][k][words[j][i] - 'A']);
                    if (i == words[j].length() - 1)
                    {
                        minDrop = min(minDrop, d[i][words[j][i] - 'A'][l]);
                        minDrop = min(minDrop, d[i][k][words[j][i] - 'A']);
                    }
                }
            }
        }
        cout << minDrop << endl;
    }
}