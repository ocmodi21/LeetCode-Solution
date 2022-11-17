#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(string &st, int open, int close, int mx)
{
    if (st.size() == 2 * mx)
    {
        ans.push_back(st);
        return;
    }
    if (open < mx)
    {
        st.push_back('(');
        solve(st, open + 1, close, mx);
        st.pop_back();
    }
    if (close < open)
    {
        st.push_back(')');
        solve(st, open, close + 1, mx);
        st.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    string st;
    solve(st, 0, 0, n);
    return ans;
}