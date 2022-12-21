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

int minDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftNode = minDepth(root->left);
    int rightNode = minDepth(root->right);
    if (leftNode == 0)
        return rightNode + 1;
    else if (rightNode == 0)
        return leftNode + 1;
    else
        return min(leftNode, rightNode) + 1;
}