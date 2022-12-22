#include <iostream>

using namespace std;

typedef struct Node
{
    int value;
    Node *next;
    Node *prev;
} node;

int *arr = new int[100001];
node **c = new node *[100001];
node *ne = NULL;

void append(node **start, int value)
{
    if (*start == NULL)
    {
        node *new_node = new node;
        new_node->value = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    node *last = (*start)->prev;
    node *new_node = new node;
    new_node->value = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
    return;
}

void insert_end(node **head, node *new_node)
{
    if (*head == NULL)
    {
        new_node->next = new_node->prev = new_node;
        *head = new_node;
        return;
    }
    node *last = (*head)->prev;
    new_node->next = *head;
    (*head)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
    return;
}

void reverse(node **head)
{
    if (!(*head))
    {
        return;
    }
    node *new_head = NULL;
    node *last = (*head)->prev;
    node *curr = last, *prev;

    while (curr->prev != last)
    {
        prev = curr->prev;
        insert_end(&new_head, curr);
        curr = prev;
    }
    insert_end(&new_head, curr);
    *head = new_head;
    return;
}

void display(int l)
{
    for (int i = 0; i < l; i++)
    {
        node *temp = c[i];

        cout << "row " << i << " -> ";
        while (temp->next != c[i])
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << temp->value << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l, n, t, y = 1, w;
    append(&ne, -1);
    char z;
    cin >> l >> n;
    for (int i = 0; i < l; i++)
    {
        c[i] = NULL;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            append(&c[i], y);
            arr[y] = i;
            y++;
        }
    }
    // cout << "ARRAY : ";
    // for (int i = 1; i < y; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    node *it = c[0];
    node *head = c[0];
    node *tail = c[0]->prev;

    // display(l);

    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> z;
        // cout << "input is " << z << " ";
        if (z == 'F')
        {
            // cout << endl;
            if (it != tail)
            {
                it = it->next;
            }
        }
        else if (z == 'B')
        {
            // cout << endl;
            if (it != head)
            {
                it = it->prev;
            }
        }
        else if (z == 'C')
        {
            cin >> w;
            int idx = arr[w];
            bool re = false;
            if (c[idx]->value != w)
            {
                // cout << "REVERSE\n";
                re = true;
            }
            if (it != tail)
            {
                node *temp = c[0];
                node *rm = c[0];
                l++;
                rm = it;
                it = it->next;
                c[l - 1] = it;
                temp = c[l - 1];
                arr[c[l - 1]->value] = l - 1;
                arr[tail->value] = l - 1;
                temp->prev = head->prev;
                tail->next = temp;
                rm->next = head;
                head->prev = rm;
                it = rm;
                tail = it;
                // cout << "MOVE COMPLETE" << endl;
            }
            // cout << "checking current " << it->v << " ";
            // cout << "previous " << it->prev->v << " next " << it->next->v << endl;
            // display(l);
            if (re)
            {
                // cout << endl;
                reverse(&c[idx]);
                // display(l);
            }
            node *tail1 = tail;
            node *tail2 = c[idx]->prev;
            node *head1 = head;
            node *head2 = c[idx];
            tail1 = head1->prev;
            tail2 = head2->prev;
            head1->prev = tail2;
            tail1->next = head2;
            head2->prev = tail1;
            tail2->next = head1;
            tail = tail2;
            // cout << head->prev->v << " " << head->v << " " << head->next->v << endl;
            // cout << tail->prev->v << " " << tail->v << " " << tail->next->v << endl;
            c[idx] = ne;
            arr[head->value] = 0;
            arr[tail->value] = 0;
            it = it->next;
        }
        // cout << "CURRENT : ";
        cout << it->value << "\n";
        // display(l);
        // cout << "ARRAY : ";
        // for (int i = 1; i < y; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        // cout << endl;
    }
    // display(l);
    return 0;
}

// g++ -std=c++11 -Wall -o chain2.exe chain2.cpp && echo complete && chain2.exe < t.txt > o2.txt