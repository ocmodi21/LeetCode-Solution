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

// In left view go first for left and then right in preorder
void reversePreorder(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (ans.size() == level)
        ans.push_back(root->val);
    reversePreorder(root->right, level + 1, ans);
    reversePreorder(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    reversePreorder(root, 0, ans);
    return ans;
}