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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    else
    {
        ListNode *p = head;
        ListNode *q = head->next;
        while (q)
        {
            if (p->val != q->val)
            {
                p = q;
                q = q->next;
            }
            else
            {
                p->next = q->next;
                q = p->next;
            }
        }
    }
    return head;
}