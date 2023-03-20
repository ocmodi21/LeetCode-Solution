#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
    stack<string> backSt, forwardSt;
    string current;

public:
    BrowserHistory(string homepage)
    {
        current = homepage;
    }

    void visit(string url)
    {
        while (!forwardSt.empty())
            forwardSt.pop();
        backSt.push(current);
        current = url;
    }

    string back(int steps)
    {
        while (!backSt.empty() && steps--)
        {
            forwardSt.push(current);
            current = backSt.top();
            backSt.pop();
        }
        return current;
    }

    string forward(int steps)
    {
        while (!forwardSt.empty() && steps--)
        {
            backSt.push(current);
            current = forwardSt.top();
            forwardSt.pop();
        }
        return current;
    }
};