#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approch-1
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    // finding middle node
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // reverse slow->next linked list
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (slow->val != head->val)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

// Approch-2
bool isPalindrome(ListNode *head)
{
    vector<int> v;
    ListNode *p = head;
    while (p)
    {
        v.push_back(p->val);
        p = p->next;
    }
    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        if (v[i] != v[j])
            return 0;
    }
    return 1;
}