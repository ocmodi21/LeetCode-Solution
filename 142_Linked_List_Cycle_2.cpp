#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *p = head, *q = head, *r = head;
    while (q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
        {
            while (p != r)
            {
                p = p->next;
                r = r->next;
            }
            return r;
        }
    }
    return NULL;
}