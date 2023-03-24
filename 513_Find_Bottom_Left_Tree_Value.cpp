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
    int bottomLeftVal = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (count == 0)
                bottomLeftVal = temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            count++;
        }
    }
    return bottomLeftVal;
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