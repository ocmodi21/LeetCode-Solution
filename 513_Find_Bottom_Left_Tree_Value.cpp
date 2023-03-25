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

// Approch-1-BFS
int findBottomLeftValue(TreeNode *root)
{
    int bottomLeftValue;
    if (!root)
        return NULL;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        bottomLeftValue = q.front()->val;
        while (size--)
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
    return bottomLeftValue;
}

// Approch-2-DFS
int bottomleft = 0, lowestlvl = -1;
void dfs(TreeNode *root, int lvl)
{
    if (lvl > lowestlvl)
    {
        lowestlvl = lvl;
        bottomleft = root->val;
    }
    if (root->left)
        dfs(root->left, lvl + 1);
    if (root->right)
        dfs(root->right, lvl + 1);
}
int findBottomLeftValue(TreeNode *root)
{
    dfs(root, 0);
    return bottomleft;
}