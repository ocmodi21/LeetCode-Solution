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

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    ListNode *curr = head;
    int count = 1;
    while (curr->next && ++count)
        curr = curr->next;

    curr->next = head;
    k = k % count;
    k = count - k;
    while (k--)
        curr = curr->next;

    head = curr->next;
    curr->next = NULL;
    return head;
}