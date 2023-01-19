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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *p, *r;
    TreeNode *t = root;
    if (root == NULL)
    {
        p = new TreeNode(val);
        root = p;
        return root;
    }

    while (t != NULL)
    {
        r = t;
        if (val < t->val)
        {
            t = t->left;
        }
        else if (val > t->val)
        {
            t = t->right;
        }
        else
        {
            break;
        }
    }

    p = new TreeNode(val);
    if (val < r->val)
        r->left = p;
    else
        r->right = p;
    return root;
}