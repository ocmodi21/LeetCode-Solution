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

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *node = root;

    while (node != NULL || !st.empty())
    {
        if (node != NULL)
        {
            ans.push_back(node->val);
            st.push(node);
            node = node->left;
        }
        else
        {
            node = st.top();
            st.pop();
            node = node->right;
        }
    }
    return ans;
}