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

void bfs(TreeNode *root, priority_queue<long long> &pq)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        long long sum = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        pq.push(sum);
    }
}
long long kthLargestLevelSum(TreeNode *root, int k)
{
    priority_queue<long long> pq;
    bfs(root, pq);

    if (pq.size() < k)
        return -1;
    k--;
    while (k--)
    {
        pq.pop();
    }
    return pq.top();
}