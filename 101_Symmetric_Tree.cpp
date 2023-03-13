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

bool solve(TreeNode *root1, TreeNode *root2)
{
    if (!root1)
        return !root2;
    if (!root2)
        return !root1;
    return (root1->val == root2->val) && solve(root1->left, root2->right) && solve(root1->right, root2->left);
}
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return solve(root->left, root->right);
}