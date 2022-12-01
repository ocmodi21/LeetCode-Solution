#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head)
{
    ListNode *temp = head;
    vector<int> res;
    while (temp)
    {
        res.push_back(temp->val);
        temp = temp->next;
    }

    if (res.size() <= 2)
        return;

    int n = res.size();
    int i = 0, idx = 0;
    vector<int> nodes(n);
    while (idx < n)
    {
        nodes[idx] = res[i];
        idx = idx + 2;
        i++;
    }
    idx = 1, i = n - 1;
    while (idx < n)
    {
        nodes[idx] = res[i];
        i--;
        idx += 2;
    }

    ListNode *order = head;
    for (auto val : nodes)
    {
        order->val = val;
        order = order->next;
    }
}