#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s)
{
    stack<int> st;
    int ind = 0;

    for (auto i : s)
    {
        if (i == '(')
        {
            st.push(ind);
            ind = 0;
        }
        else
        {
            ind = st.top() + max(ind * 2, 1);
            st.pop();
        }
    }
    return ind;
}