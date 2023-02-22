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

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int curMin = q.front().second;
        int leftMost, rightMost;
        for (int i = 0; i < size; i++)
        {
            int cur_id = q.front().second - curMin;
            TreeNode *temp = q.front().first;
            q.pop();
            if (i == 0)
                leftMost = cur_id;
            if (i == size - 1)
                rightMost = cur_id;
            if (temp->left)
                q.push({temp->left, (long long)cur_id * 2 + 1});
            if (temp->right)
                q.push({temp->right, (long long)cur_id * 2 + 2});
        }
        ans = max(ans, rightMost - leftMost + 1);
    }
    return ans;
}