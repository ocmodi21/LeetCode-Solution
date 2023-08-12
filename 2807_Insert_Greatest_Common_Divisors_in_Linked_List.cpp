#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    if (!head->next)
        return head;

    ListNode *p = head->next;
    ListNode *q = head;
    while (p)
    {
        int val1 = p->val;
        int val2 = q->val;
        int ans = __gcd(val1, val2);

        ListNode *t = new ListNode(ans);
        t->next = p;
        q->next = t;
        q = p;
        p = p->next;
    }
    return head;
}