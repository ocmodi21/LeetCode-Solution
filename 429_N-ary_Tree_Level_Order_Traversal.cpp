#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        while (size--)
        {
            auto current = q.front();
            q.pop();

            for (auto i : current->children)
                q.push(i);

            level.push_back(current->val);
        }
        ans.push_back(level);
    }
    return ans;
}