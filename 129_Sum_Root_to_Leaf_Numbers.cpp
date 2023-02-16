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

// Approch-1-dfs
void dfs(TreeNode *root, int number, int &ans)
{
    if (!root)
        return;
    number = (number * 10) + root->val;
    if (!root->left && !root->right)
    {
        ans += number;
        return;
    }
    dfs(root->left, number, ans);
    dfs(root->right, number, ans);
}
int sumNumbers(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int number = 0;
    int ans = 0;
    dfs(root, number, ans);
    return ans;
}

// Apprcoh-2-bfs
int sumNumbers(TreeNode *root)
{
    if (root == NULL)
        return INT_MAX;
    queue<pair<TreeNode *, int>> q;
    q.push({root, root->val});
    int res = 0;
    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        int curr_sum = q.front().second;
        q.pop();
        if (curr->left != NULL)
        {
            q.push({curr->left, ((curr_sum * 10) + curr->left->val)});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, ((curr_sum * 10) + curr->right->val)});
        }
        else if (curr->left == NULL && curr->right == NULL)
        {
            res += curr_sum;
        }
    }
    return res;
}

// Approch-3
int arry(vector<int> ds)
{
    int n = ds.size();
    int x = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        x = x + (ds[i] * (pow(10, n - 1)));
        n--;
    }
    return x;
}
void helper(TreeNode *r, int &ans, vector<int> &ds)
{
    if (r == NULL)
        return;
    ds.push_back(r->val);
    if (r->left == NULL && r->right == NULL)
    {
        ans = ans + arry(ds);
    }
    helper(r->left, ans, ds);
    helper(r->right, ans, ds);
    ds.pop_back();
}
int sumNumbers(TreeNode *root)
{
    if (root == NULL)
        return 0;
    vector<int> ds;
    int ans = 0;
    helper(root, ans, ds);
    return ans;
}