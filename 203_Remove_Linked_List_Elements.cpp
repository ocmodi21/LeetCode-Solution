#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    while (head && head->val == val)
        head = head->next;
    if (!head)
        return NULL;
    ListNode *p = head;
    while (p->next)
    {
        if (p->next->val == val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}