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

// Approch-1
vector<int> ans;
void inOrder(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return;
    inOrder(root->left, low, high);
    if (root->val >= low && root->val <= high)
        ans.push_back(root->val);
    inOrder(root->right, low, high);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    inOrder(root, low, high);
    int sum = 0;
    for (auto x : ans)
        sum += x;
    return sum;
}

// Approch-2
int sum;
void solve(TreeNode *root, int low, int high)
{
    if (!root)
        return;
    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
    }
    if (root->val > low)
        solve(root->left, low, high);
    if (root->val < high)
        solve(root->right, low, high);
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    sum = 0;
    solve(root, low, high);
    return sum;
}