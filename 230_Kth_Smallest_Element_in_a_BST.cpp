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

vector<int> ans;
void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    ans.push_back(root->val);
    inOrder(root->right);
}

int kthSmallest(TreeNode *root, int k)
{
    inOrder(root);
    if (k > ans.size())
        return -1;
    return ans[k - 1];
}