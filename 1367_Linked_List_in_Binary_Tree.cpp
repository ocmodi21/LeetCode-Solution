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

bool findSubPath(ListNode *head, TreeNode *root)
{
    if (!head)
        return true;
    if (!root)
        return false;
    return (head->val == root->val && (findSubPath(head->next, root->left) || findSubPath(head->next, root->right)));
}
bool isSubPath(ListNode *head, TreeNode *root)
{
    if (!root)
        return false;
    return findSubPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}