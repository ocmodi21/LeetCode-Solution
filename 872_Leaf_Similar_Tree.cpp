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

void findLeaf(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        ans.push_back(root->val);
    findLeaf(root->left, ans);
    findLeaf(root->right, ans);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans1, ans2;
    findLeaf(root1, ans1);
    findLeaf(root2, ans2);
    if (ans1 != ans2)
        return false;
    return true;
}