#include <iostream>
#include <vector>
#define INF 0xfffffff

using namespace std;

struct contract
{
    int c, p, w;
};

int sum_vector(vector<int> &vec)
{
    int summ = 0;
    for (auto &i : vec)
    {
        summ += i;
    }
    return summ;
}

int main()
{
    int n, k, min_cost = INF;
    vector<contract> lst;
    vector<int> box;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int ci, pi, wi;
        cin >> ci >> pi >> wi;
        lst.push_back({ci, pi, wi});
    }
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        box.push_back(t);
    }
    for (auto i : lst)
    {
        int total_cost = i.c;
        int over_weight;
        vector<vector<int>> total;
        vector<int> t;
        for (auto j : box)
        {
            if (j > i.w)
            {
                over_weight = 1;
            }
            t.push_back(j);
            if (sum_vector(t) > i.w)
            {
                t.pop_back();
                total.push_back(t);
                t.clear();
                t.push_back(j);
            }
        }
        total.push_back(t);
        t.clear();
        if (over_weight)
        {
            over_weight = 0;
            continue;
        }
        total_cost += total.size() * i.p;
        min_cost = min(total_cost, min_cost);
    }
    cout << min_cost << endl;
    return 0;
}