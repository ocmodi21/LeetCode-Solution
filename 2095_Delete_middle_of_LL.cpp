#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = NULL;
    int n;
    while (p)
    {
        n++;
        p = p->next;
    }
    p = head;
    n = (n / 2);

    if (n < 1)
        return p->next;
    else
    {
        for (int i = 0; i < n; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        p = q->next;
    }
    return head;
}