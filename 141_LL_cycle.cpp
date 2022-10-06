#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = head;

    if (head == NULL)
        return 0;

    while (p && p->next)
    {
        p = p->next->next;
        q = q->next;

        if (p == q)
            return true;
    }

    return false;
}