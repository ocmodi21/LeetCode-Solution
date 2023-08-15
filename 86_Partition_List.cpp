#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x)
{
    ListNode before(0), after(0);
    ListNode *beforePtr = &before;
    ListNode *afterPtr = &after;

    while (head)
    {
        if (head->val < x)
        {
            beforePtr->next = head;
            beforePtr = head;
        }
        else
        {
            afterPtr->next = head;
            afterPtr = head;
        }
        head = head->next;
    }

    afterPtr->next = NULL;
    beforePtr->next = after.next;
    return before.next;
}