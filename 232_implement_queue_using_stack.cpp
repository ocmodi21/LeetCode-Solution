#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> ans1, ans2;
    MyQueue() {}

    void push(int x)
    {
        while (!ans1.empty())
        {
            ans2.push(ans1.top());
            ans1.pop();
        }
        ans1.push(x);
        while (!ans2.empty())
        {
            ans1.push(ans2.top());
            ans2.pop();
        }
    }

    int pop()
    {
        int n = ans1.top();
        ans1.pop();
        return n;
    }

    int peek()
    {
        return ans1.top();
    }

    bool empty()
    {
        if (ans1.size() == 0)
            return true;
        return false;
    }
};