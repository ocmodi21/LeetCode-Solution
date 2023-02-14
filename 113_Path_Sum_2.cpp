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

void solve(TreeNode *root, int targetSum, vector<int> &ds, vector<vector<int>> &ans)
{
    if (!root)
        return;
    ds.push_back(root->val);
    if (!root->left && !root->right && root->val == targetSum)
    {
        ans.push_back(ds);
    }
    solve(root->left, targetSum - root->val, ds, ans);
    solve(root->right, targetSum - root->val, ds, ans);
    ds.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> ds;
    vector<vector<int>> ans;
    if (!root)
        return ans;
    solve(root, targetSum, ds, ans);
    return ans;
}