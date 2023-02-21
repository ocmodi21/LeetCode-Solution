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
void solve(TreeNode *root, int &count)
{
    if (!root)
        return;
    count++;
    solve(root->left, count);
    solve(root->right, count);
}
int countNodes(TreeNode *root)
{
    int count = 0;
    solve(root, count);
    return count;
}

// Approch-2
int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}
int findHeightLeft(TreeNode *node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->left;
    }
    return hght;
}
int findHeightRight(TreeNode *node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->right;
    }
    return hght;
}