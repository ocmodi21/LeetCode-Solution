#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string> &ops)
{
    int ans = 0;
    stack<int> stk;

    for (string i : ops)
    {
        if (i == "C")
            stk.pop();
        else if (i == "D")
            stk.push(stk.top() * 2);
        else if (i == "+")
        {
            int value1;
            value1 = stk.top();
            stk.pop();
            int value2;
            value2 = stk.top();
            stk.push(value1);
            stk.push(value1 + value2);
        }
        else
        {
            stk.push(stoi(i));
        }
    }
    while (stk.size() != 0)
    {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}