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

void makeParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current->left)
        {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if (current->right)
        {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent_track;
    makeParents(root, parent_track);

    unordered_map<TreeNode *, bool> visited;
    int curr_level = 0;
    visited[target] = true;
    queue<TreeNode *> q;
    q.push(target);
    while (!q.empty())
    {
        int size = q.size();
        if (curr_level++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        ans.push_back(temp->val);
    }
    return ans;
}