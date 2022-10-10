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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *p = head;
    ListNode *q = NULL;
    int x = 0;
    while (p)
    {
        x++;
        p = p->next;
    }

    p = head;

    int a = x - n;
    if (a == 0)
    {
        return p->next;
    }
    else
    {
        int i = 0;
        while (i != a && p)
        {
            q = p;
            p = p->next;
            i++;
        }
        q->next = p->next;
        p = q->next;
    }
    return head;
}