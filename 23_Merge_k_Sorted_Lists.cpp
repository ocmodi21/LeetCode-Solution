#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;

    ListNode *head = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        ListNode *p = new ListNode(-1);
        ListNode *q = p;
        ListNode *current = lists[i];

        while (head && current)
        {
            if (head->val <= current->val)
            {
                q->next = head;
                head = head->next;
            }
            else
            {
                q->next = current;
                current = current->next;
            }
            q = q->next;
        }

        if (head)
            q->next = head;
        if (current)
            q->next = current;
        q = p->next;
        head = q;
    }
    return head;
}