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

bool isEvenOddTree(TreeNode *root)
{
    if (root->val % 2 == 0)
        return false;
    int prev = 0;
    bool oddLevel = false;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        if (oddLevel)
            prev = INT_MAX;
        else
            prev = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (oddLevel && (current->val % 2 != 0 ||
                             prev <= current->val))
                return false;
            else if (!oddLevel && (current->val % 2 == 0 ||
                                   prev >= current->val))
                return false;
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            prev = current->val;
        }
        oddLevel = !oddLevel;
    }
    return true;
}