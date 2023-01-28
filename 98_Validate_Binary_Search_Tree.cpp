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

bool valid(TreeNode *root, TreeNode *currLeft, TreeNode *currRight)
{
    if (!root)
        return true;
    if (currLeft && root->val <= currLeft->val)
        return false;
    if (currRight && currRight->val <= root->val)
        return false;
    return valid(root->left, currLeft, root) && valid(root->right, root, currRight);
}
bool isValidBST(TreeNode *root)
{
    return valid(root, NULL, NULL);
}