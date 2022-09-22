#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *p = list1;
    ListNode *q = list2;
    ListNode *r = new ListNode;
    ListNode *temp = r;

    while (p && q)
    {
        if (p->val < q->val)
        {
            temp->next = p;
            p = p->next;
        }
        else
        {
            temp->next = q;
            q = q->next;
        }
        temp = temp->next;
    }
    if (p)
        temp->next = p;
    else
        temp->next = q;
    return r->next;
}