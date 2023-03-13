#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head)
{
    if (!head)
        return NULL;
    if (!head->next)
        return new TreeNode(head->val);

    ListNode *p = head;
    ListNode *q = head;
    ListNode *r = NULL;

    while (p->next)
    {
        p = p->next;
        if (p->next)
            p = p->next;
        r = q;
        q = q->next;
    }
    TreeNode *root = new TreeNode(q->val);
    r->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(q->next);
    return root;
}