#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int l, int r)
{
    if (!head || !head->next || l == r)
        return head;

    ListNode *temp = new ListNode(0);
    temp->next = head;

    int i;
    ListNode *t1 = temp, *t2, *prev, *nex, *t;

    for (i = 0; i < l - 1; i++)
        t1 = t1->next;

    t2 = t = t1->next;
    prev = NULL;

    for (i = l; i <= r; i++)
    {
        nex = t2->next;
        t2->next = prev;
        prev = t2;
        t2 = nex;
    }

    t->next = t2;
    t1->next = prev;

    return temp->next;
}