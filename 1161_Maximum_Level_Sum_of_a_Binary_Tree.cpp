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

int maxLevelSum(TreeNode *root)
{
    int level = 0;
    int maxi = INT_MIN;
    int maxSumLevel = -1;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        level++;
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (sum > maxi)
        {
            maxi = sum;
            maxSumLevel = level;
        }
    }
    return maxSumLevel;
}