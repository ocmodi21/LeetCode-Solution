#include <bits/stdc++.h>
using namespace std;

// Approch-1
string makeGood(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && ((st.top() - 'a' == s[i] - 'A') || (st.top() - 'A' == s[i] - 'a')))
            st.pop();
        else
            st.push(s[i]);
    }

    string ans;
    while (!st.empty())
    {
        char cur = st.top();
        st.pop();
        ans = cur + ans;
    }

    return ans;
}

// Approch-2
string makeGood(string s)
{
    vector<char> ans;
    for (auto it : s)
    {
        if (ans.size() && abs(ans.back() - it) == 32)
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(it);
        }
    }
    string res(ans.begin(), ans.end());
    return res;
}