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

int maxCounter = 0;
int longestZigZag(TreeNode *root)
{
    maxZigzag(root->left, true, 1);
    maxZigzag(root->right, false, 1);
    return maxCounter;
}
void maxZigzag(TreeNode *root, bool left, int counter)
{
    if (!root)
        return;
    maxCounter = max(counter, maxCounter);

    if (left)
    {
        maxZigzag(root->left, true, 1);
        maxZigzag(root->right, false, counter + 1);
    }
    else
    {
        maxZigzag(root->left, true, counter + 1);
        maxZigzag(root->right, false, 1);
    }
}