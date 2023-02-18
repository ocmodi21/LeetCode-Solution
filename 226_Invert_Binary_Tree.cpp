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
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return NULL;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// Approch-2-dfs
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return NULL;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
}

// Approch-3-bfs
TreeNode *invertTree(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
        return NULL;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        swap(root->left, root->right);
    }
    return root;
}