#include <iostream>
#include <vector>
#include <stack>
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
stack<int> st;

bool is_reversed(int idx)
{
    return reversed[idx];
}

bool isNumSecond(int num, int idx)
{
    return num == vec.at(idx).second;
}

int find_next(int n)
{
    return pairs_next[n];
}

int find_previous(int n)
{
    return pairs_previous[n];
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
    if (is_reversed(vec.at(idx).first))
    {
        p.first = num - 1;
    }
    else
    {
        p.first = num + 1;
    }
    p.second = vec.at(idx).second;
    vec.at(idx).second = num;
    where[num] = idx;
    if (p.second == tail)
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
    if (find_previous(vec.at(idx).first) == 0)
    {
        int temp = vec[idx].first;
        vec[idx].first = vec[idx].second;
        vec[idx].second = temp;
        reversed[vec.at(idx).second] = !reversed[vec.at(idx).second];
        reversed[vec.at(idx).first] = !reversed[vec.at(idx).first];
    }
    else
    {
        while (ptr != 0)
        {
            int temp = vec[ptr].first;
            vec[ptr].first = vec[ptr].second;
            vec[ptr].second = temp;

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

            ptr = where[find_next(vec.at(ptr).second)];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    st.push(1);
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

    heads = vec.at(pairs_select).first;
    tail = vec.at(pairs_select).second;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == 'F')
        {
            int te;
            if (!is_reversed(vec.at(pairs_select).first) && check_range(pairs_select, st.top() + 1))
            {
                te = st.top() + 1;
                st.push(te);
            }
            else if (is_reversed(vec.at(pairs_select).first) && check_range(pairs_select, st.top() - 1))
            {
                te = st.top() - 1;
                st.push(te);
            }
            else if ((st.top() != heads || st.top() != tail) && find_next(vec.at(pairs_select).second))
            {
                pairs_select = where[find_next(vec.at(pairs_select).second)];
                st.push(vec.at(pairs_select).first);
            }
        }
        else if (c == 'B')
        {
            if (!is_reversed(vec.at(pairs_select).first) && check_range(pairs_select, st.top() - 1))
            {
                st.pop();
            }
            else if (is_reversed(vec.at(pairs_select).first) && check_range(pairs_select, st.top() + 1))
            {
                st.pop();
            }
            else if (find_previous(vec.at(pairs_select).first))
            {
                pairs_select = where[find_previous(vec.at(pairs_select).first)];
                st.pop();
            }
        }
        else if (c == 'C')
        {
            cin >> y;
            if (isNumSecond(y, where[y]) && vec.at(where[y]).first != vec.at(where[y]).second && find_next(vec.at(where[y]).second) == 0)
            {
                pairs_reverse(where[y]);
            }
            else if (pairs_previous[vec.at(where[y]).first] != 0)
            {
                pairs_reverse(where[y]);
            }
            if (st.top() == tail)
            {
                pairs_join(vec.at(pairs_select).second, y);
            }
            else if ((vec.at(where[st.top()]).first == st.top() && vec.at(where[st.top()]).second == st.top()) || (st.top() != vec.at(where[st.top()]).first && find_next(vec.at(where[st.top()]).second) > 0))
            {
                pairs_previous[find_next(vec.at(where[st.top()]).second)] = 0;
                pairs_next[st.top()] = 0;
                pairs_join(st.top(), y);
            }
            else
            {
                pairs_cut(st.top(), pairs_select);
                pairs_join(st.top(), y);
            }

            pairs_select = where[find_next(vec.at(pairs_select).second)];

            tail = vec.at(pairs_select).second;
            while (1)
            {
                int temp = find_next(tail);
                if (temp != 0)
                {
                    tail = temp;
                    tail = vec.at(where[tail]).second;
                }
                else
                {
                    break;
                }
            }
            st.push(vec.at(pairs_select).first);
        }
        cout << st.top() << "\n";
    }

    return 0;
}