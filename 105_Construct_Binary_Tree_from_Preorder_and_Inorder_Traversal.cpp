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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
        m[inorder[i]] = i;
    TreeNode *root = formtree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    return root;
}
TreeNode *formtree(vector<int> &preorder, int prst, int pren, vector<int> &inorder, int inst, int inen, map<int, int> &m)
{
    if (prst > pren || inst > inen)
        return NULL;
    TreeNode *root = new TreeNode(preorder[prst]);
    int pos = m[preorder[prst]];
    int lft = pos - inst;
    root->left = formtree(preorder, prst + 1, prst + lft, inorder, inst, pos - 1, m);
    root->right = formtree(preorder, prst + lft + 1, pren, inorder, pos + 1, inen, m);
    return root;
}