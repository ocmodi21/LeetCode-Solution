#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head)
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
ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
{
    ListNode *l1 = reverse(list1);
    ListNode *l2 = reverse(list2);
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *newnode = new ListNode(sum % 10);
        temp->next = newnode;
        temp = temp->next;
    }
    return reverse(dummy->next);
}