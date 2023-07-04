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

void dfs(TreeNode *root, int &sum)
{
    if (!root)
        return;
    if (root->right)
        dfs(root->right, sum);
    root->val += sum;
    sum = root->val;
    if (root->left)
        dfs(root->left, sum);
}
TreeNode *convertBST(TreeNode *root)
{
    int sum = 0;
    dfs(root, sum);
    return root;
}