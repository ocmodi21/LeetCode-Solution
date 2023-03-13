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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return NULL;

    int curr = root->val;
    if (curr < p->val && curr < q->val)
        return lowestCommonAncestor(root->right, p, q);
    if (curr > p->val && curr > q->val)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}