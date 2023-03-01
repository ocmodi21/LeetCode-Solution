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

string dfs(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode *> &ans)
{
    if (!root)
        return "#";

    string left = dfs(root->left, mp, ans);
    string right = dfs(root->right, mp, ans);
    string res = to_string(root->val) + "," + left + "," + right;

    mp[res]++;
    if (mp[res] == 2)
        ans.push_back(root);
    return res;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    unordered_map<string, int> mp;
    vector<TreeNode *> ans;
    dfs(root, mp, ans);
    return ans;
}