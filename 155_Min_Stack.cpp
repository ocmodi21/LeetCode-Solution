#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int m = INT_MAX;

void push(int val)
{
    if (val <= m)
    {
        s.push(m);
        m = val;
    }
    s.push(val);
}

void pop()
{
    if (s.top() == m)
    {
        s.pop();
        m = s.top();
    }
    s.pop();
}

int top()
{
    return s.top();
}

int getMin()
{
    return m;
}