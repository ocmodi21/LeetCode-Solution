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

bool isCompleteTree(TreeNode *root)
{
    if (!root)
        return true;
    queue<TreeNode *> q;
    bool isNULL = false;
    q.push(root);
    while (!q.empty())
    {
        if (!q.front())
            isNULL = true;
        else
        {
            if (isNULL)
                return false;
            q.push(q.front()->left);
            q.push(q.front()->right);
        }
        q.pop();
    }
    return true;
}