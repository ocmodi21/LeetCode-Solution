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

int ans = INT_MAX;
int last = -1;
void dfs(TreeNode *root)
{
    if (!root)
        return;
    dfs(root->left);
    if (last != -1)
    {
        ans = min(ans, root->val - last);
    }
    last = root->val;
    dfs(root->right);
}
int minDiffInBST(TreeNode *root)
{
    dfs(root);
    return ans;
}