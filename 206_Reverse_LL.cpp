#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = NULL;
    ListNode *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return head;
}
