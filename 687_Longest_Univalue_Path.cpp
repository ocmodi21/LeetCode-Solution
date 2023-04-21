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

int ans = 0;
int solve(TreeNode *root, int prev)
{
    if (root == NULL)
        return 0;
    if (root->val != prev)
    {
        int left = solve(root->left, root->val);
        int right = solve(root->right, root->val);
        ans = max(ans, left + right + 1);
        return 0;
    }
    int left = solve(root->left, prev);
    int right = solve(root->right, prev);
    ans = max(ans, 1 + left + right);
    return 1 + max(left, right);
}
int longestUnivaluePath(TreeNode *root)
{
    if (root == NULL)
        return 0;
    solve(root, root->val);
    return ans - 1;
}