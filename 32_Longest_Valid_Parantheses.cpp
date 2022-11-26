#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> ans;
    int count = 0;
    ans.push(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            ans.push(i);
        }
        else if (s[i] == ')')
        {
            ans.pop();
            if (ans.empty())
            {
                ans.push(i);
            }
            else
            {
                count = max(count, i - ans.top());
            }
        }
    }
    return count;
}