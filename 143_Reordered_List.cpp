#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approch-1
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

// Approch-2
ListNode *middle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
void reorderList(ListNode *head)
{
    ListNode *mid = middle(head);
    ListNode *rev = reverse(mid->next);
    mid->next = NULL;
    while (head && rev)
    {
        ListNode *p = head->next;
        ListNode *q = rev->next;
        head->next = rev;
        head->next->next = p;
        head = p;
        rev = q;
    }
}