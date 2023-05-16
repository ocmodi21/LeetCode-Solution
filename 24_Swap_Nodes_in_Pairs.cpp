#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *p = head;
    ListNode *q = head->next;
    p->next = swapPairs(q->next);
    q->next = p;
    return q;
}