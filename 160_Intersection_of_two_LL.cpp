#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p = headA;
    ListNode *q = headB;

    int a = 0;
    int b = 0;

    while (p != NULL)
    {
        a++;
        p = p->next;
    }

    while (q != NULL)
    {
        b++;
        q = q->next;
    }

    if (a > b)
    {
        for (int i = 0; i < abs(a - b); i++)
            headA = headA->next;
    }
    else
    {
        for (int i = 0; i < abs(a - b); i++)
            headB = headB->next;
    }

    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    if (headA && headB)
        return headA;
    else
        return NULL;
}