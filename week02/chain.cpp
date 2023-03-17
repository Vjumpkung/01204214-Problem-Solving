#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int where[100001] = {0};
int pairs_next[100001] = {0};
int pairs_previous[100001] = {0};
int reversed[100001] = {0};
int heads;
int tail, x = 1;
pair<int, int> pa;
vector<pair<int, int>> vec = {{0, 0}};
vector<int> st = {1};

bool isNumSecond(int num, int idx)
{
    return num == vec.at(idx).second;
}

bool check_range(int idx, int num)
{
    int first_num = min(vec.at(idx).first, vec.at(idx).second);
    int second_num = max(vec.at(idx).first, vec.at(idx).second);

    if (num >= first_num && num <= second_num)
    {
        return true;
    }

    return false;
}

void pairs_join(int from, int too)
{
    pairs_next[from] = too;
    pairs_previous[too] = from;
}

void pairs_cut(int num, int idx)
{
    pair<int, int> p;
    if (reversed[vec.at(idx).first])
    {
        p.first = num - 1;
    }
    else
    {
        p.first = num + 1;
    }
    p.second = vec.at(idx).second;
    vec.at(idx).second = num;
    if (vec.at(idx).first > vec.at(idx).second)
    {
        reversed[vec.at(idx).first] = 1;
        reversed[vec.at(idx).second] = 1;
    }
    else
    {
        reversed[vec.at(idx).first] = 0;
        reversed[vec.at(idx).second] = 0;
    }
    where[num] = idx;
    if (p.second == vec.at(where[p.second]).second && pairs_next[vec.at(where[p.second]).second] == 0)
    {
        pairs_next[p.first] = 0;
        pairs_previous[p.second] = 0;
    }
    else
    {
        pairs_previous[p.first] = 0;
    }
    if (p.first > p.second)
    {
        reversed[p.first] = 1;
        reversed[p.second] = 1;
    }
    else
    {
        reversed[p.first] = 0;
        reversed[p.second] = 0;
    }
    vec.push_back(p);
    where[p.first] = vec.size() - 1;
    where[p.second] = vec.size() - 1;
}

void pairs_reverse(int idx)
{
    int ptr = idx;
    if (pairs_previous[vec.at(idx).first] == 0)
    {
        int temp = vec.at(idx).first;
        vec.at(idx).first = vec.at(idx).second;
        vec.at(idx).second = temp;
        reversed[vec.at(idx).second] = !reversed[vec.at(idx).second];
        reversed[vec.at(idx).first] = !reversed[vec.at(idx).first];
    }
    else
    {
        while (ptr != 0)
        {
            int temp = vec.at(ptr).first;
            vec.at(ptr).first = vec.at(ptr).second;
            vec.at(ptr).second = temp;
            reversed[vec.at(ptr).second] = !reversed[vec.at(ptr).second];
            reversed[vec.at(ptr).first] = !reversed[vec.at(ptr).first];

            if (vec.at(ptr).first != vec.at(ptr).second)
            {
                swap(pairs_next[vec.at(ptr).first], pairs_previous[vec.at(ptr).first]);
                swap(pairs_next[vec.at(ptr).second], pairs_previous[vec.at(ptr).second]);
            }
            else
            {
                swap(pairs_next[vec.at(ptr).first], pairs_previous[vec.at(ptr).first]);
            }
            ptr = where[pairs_next[vec.at(ptr).second]];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int p, n, m, pairs_select = 1, y;
    char c;
    cin >> p >> n;

    for (int i = 0; i < p; i++)
    {
        cin >> m;
        pa.first = x;
        pa.second = x + m - 1;
        where[x] = i + 1;
        where[x + m - 1] = i + 1;
        x += m;
        vec.push_back(pa);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == 'F')
        {
            int te;
            if (!(reversed[vec.at(pairs_select).first] && reversed[vec.at(pairs_select).second]) && check_range(pairs_select, st[st.size() - 1] + 1))
            {
                te = st[st.size() - 1] + 1;
                st.push_back(te);
            }
            else if ((reversed[vec.at(pairs_select).first] && reversed[vec.at(pairs_select).second]) && check_range(pairs_select, st[st.size() - 1] - 1))
            {
                te = st[st.size() - 1] - 1;
                st.push_back(te);
            }
            else if (pairs_next[vec.at(pairs_select).second] != 0)
            {
                pairs_select = where[pairs_next[vec.at(pairs_select).second]];
                st.push_back(vec.at(pairs_select).first);
            }
        }
        else if (c == 'B')
        {
            if (!(reversed[vec.at(pairs_select).first] && reversed[vec.at(pairs_select).second]) && check_range(pairs_select, st[st.size() - 1] - 1))
            {
                st.pop_back();
            }
            else if ((reversed[vec.at(pairs_select).first] && reversed[vec.at(pairs_select).second]) && check_range(pairs_select, st[st.size() - 1] + 1))
            {
                st.pop_back();
            }
            else if (pairs_previous[vec.at(pairs_select).first])
            {
                pairs_select = where[pairs_previous[vec.at(pairs_select).first]];
                st.pop_back();
            }
        }
        else if (c == 'C')
        {
            cin >> y;
            if ((isNumSecond(y, where[y]) && vec[where[y]].first != vec[where[y]].second && pairs_next[vec[where[y]].second] == 0) || (pairs_previous[vec[where[y]].first] != 0))
            {
                pairs_reverse(where[y]);
            }
            if (st[st.size() - 1] == vec.at(where[st[st.size() - 1]]).second && pairs_next[vec.at(where[st[st.size() - 1]]).second] == 0)
            {
                pairs_join(vec.at(pairs_select).second, y);
            }
            else if ((vec.at(where[st[st.size() - 1]]).first == st[st.size() - 1] && vec.at(where[st[st.size() - 1]]).second == st[st.size() - 1]) || (st[st.size() - 1] != vec.at(where[st[st.size() - 1]]).first && pairs_next[vec.at(where[st[st.size() - 1]]).second] > 0))
            {
                pairs_previous[pairs_next[vec.at(where[st[st.size() - 1]]).second]] = 0;
                pairs_next[st[st.size() - 1]] = 0;
                pairs_join(st[st.size() - 1], y);
            }
            else
            {
                pairs_cut(st[st.size() - 1], pairs_select);
                pairs_join(st[st.size() - 1], y);
            }

            pairs_select = where[pairs_next[vec.at(pairs_select).second]];

            st.push_back(vec.at(pairs_select).first);
        }
        cout << st[st.size() - 1] << "\n";
    }

    return 0;
}