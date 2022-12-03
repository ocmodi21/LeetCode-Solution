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

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    while (!st.empty() || root)
    {
        if (root)
        {
            st.push(root->left);
            ans.push_back(root->val);
            root = root->right;
        }
        else
        {
            root = st.top();
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}