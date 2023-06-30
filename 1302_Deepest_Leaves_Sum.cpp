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

// Approch-1-DFS
int TreeHeight(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(TreeHeight(root->left), TreeHeight(root->right));
}
void buildDeepNodes(TreeNode *root, int depth, vector<int> &deepNodes, int height)
{
    if (!root)
        return;
    depth += 1;
    if (depth == height)
    {
        deepNodes.push_back(root->val);
    }
    buildDeepNodes(root->left, depth, deepNodes, height);
    buildDeepNodes(root->right, depth, deepNodes, height);
}
int deepestLeavesSum(TreeNode *root)
{
    vector<int> deepNodes;
    int depth = 0;
    int height = TreeHeight(root);
    buildDeepNodes(root, depth, deepNodes, height);
    return accumulate(deepNodes.begin(), deepNodes.end(), 0);
}

// Approch-2-BFS
int deepestLeavesSum(TreeNode *root)
{
    int sum = 0, n;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        sum = 0, n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto top = q.front();
            q.pop();
            sum += top->val;
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
    }
    return sum;
}
