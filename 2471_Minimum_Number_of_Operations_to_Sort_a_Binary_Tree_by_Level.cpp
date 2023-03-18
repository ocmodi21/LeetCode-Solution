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

int count(vector<int> v)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < v.size(); i++)
    {
        vec.push_back({v[i], i});
    }
    int count = 0;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        while (i != vec[i].second)
        {
            swap(vec[i], vec[vec[i].second]);
            count++;
        }
    }
    return count;
}
int minimumOperations(TreeNode *root)
{
    int ans = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            v.push_back(temp->val);
        }
        ans += count(v);
    }
    return ans;
}