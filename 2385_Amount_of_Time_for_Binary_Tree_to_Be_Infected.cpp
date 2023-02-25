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

TreeNode *createMapping(TreeNode *root, int start, map<TreeNode *, TreeNode *> &nodeToParent)
{
    TreeNode *ans = NULL;
    queue<TreeNode *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        if (current->val == start)
            ans = current;

        if (current->left)
        {
            nodeToParent[current->left] = current;
            q.push(current->left);
        }
        if (current->right)
        {
            nodeToParent[current->right] = current;
            q.push(current->right);
        }
    }
    return ans;
}

void solve(TreeNode *root, map<TreeNode *, TreeNode *> &nodeToParent, int &time)
{
    map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(root);
    visited[root] = 1;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();

            if (current->left && !visited[current->left])
            {
                flag = true;
                visited[current->left] = 1;
                q.push(current->left);
            }
            if (current->right && !visited[current->right])
            {
                flag = true;
                visited[current->right] = 1;
                q.push(current->right);
            }
            if (nodeToParent[current] && !visited[nodeToParent[current]])
            {
                flag = true;
                visited[nodeToParent[current]] = 1;
                q.push(nodeToParent[current]);
            }
        }
        if (flag == true)
            time++;
    }
}

int amountOfTime(TreeNode *root, int start)
{
    map<TreeNode *, TreeNode *> nodeToParent;
    TreeNode *target = createMapping(root, start, nodeToParent);
    int time = 0;
    solve(target, nodeToParent, time);
    return time;
}