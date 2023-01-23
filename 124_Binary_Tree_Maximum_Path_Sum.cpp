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

int maxPathDown(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = max(0, maxPathDown(root->left, maxi));
    int right = max(0, maxPathDown(root->right, maxi));
    maxi = max(maxi, root->val + left + right);
    return root->val + max(left, right);
}
int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}