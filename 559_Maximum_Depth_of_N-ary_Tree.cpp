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

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int depth = 0;
    for (auto child : root->children)
        depth = max(depth, maxDepth(child));
    return 1 + depth;
}