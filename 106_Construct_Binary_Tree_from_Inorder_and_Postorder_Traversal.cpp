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

TreeNode *construct(vector<int> &in, int inStart, int inEnd, vector<int> &post, int postStart, int postEnd, map<int, int> &inMap)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;
    TreeNode *root = new TreeNode(post[postEnd]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = construct(in, inStart, inRoot - 1, post, postStart, postStart + numsLeft - 1, inMap);
    root->right = construct(in, inRoot + 1, inEnd, post, postStart + numsLeft, postEnd - 1, inMap);
    return root;
}

TreeNode *buildTree(vector<int> &in, vector<int> &post)
{
    map<int, int> inMap;
    for (int i = 0; i < in.size(); i++)
        inMap[in[i]] = i;
    return construct(in, 0, in.size() - 1, post, 0, post.size() - 1, inMap);
}