#include <iostream>
#include <vector>

using namespace std;

struct WintSch
{
    int start;
    int end;
    int profit;
};

int main()
{
    int n;
    cin >> n;
    vector<WintSch> wintSch(n);
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        cin >> wintSch[i].start >> wintSch[i].end >> wintSch[i].profit;
    }
    int maxProfit[n];
    vector<int> select[n];
    for (int i = 0; i < n; i++)
    {
        maxProfit[i] = wintSch[i].profit;
        select[i].push_back(i);
        for (int j = 0; j < i; j++)
        {
            if (wintSch[j].end <= wintSch[i].start)
            {
                if (maxProfit[i] < maxProfit[j] + wintSch[i].profit)
                {
                    maxProfit[i] = maxProfit[j] + wintSch[i].profit;
                    select[i] = select[j];
                    select[i].push_back(i);
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < maxProfit[i])
        {
            max = maxProfit[i];
            answer = select[i];
        }
    }
    cout << max << endl;
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}