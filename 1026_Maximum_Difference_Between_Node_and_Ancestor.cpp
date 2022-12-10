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

int find(TreeNode *root, int maxNum, int minNum)
{
    if (root == NULL)
        return maxNum - minNum;

    maxNum = max(maxNum, root->val);
    minNum = min(minNum, root->val);

    return max(find(root->left, maxNum, minNum), find(root->right, maxNum, minNum));
}

int maxAncestorDiff(TreeNode *root)
{
    int maxNum = 0, minNum = 100000;
    return find(root, maxNum, minNum);
}