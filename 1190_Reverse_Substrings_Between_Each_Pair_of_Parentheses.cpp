#include <bits/stdc++.h>
using namespace std;

// Approch-1
string reverseParentheses(string s)
{
    stack<char> st;
    string reverse = "";
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ')')
        {
            st.push(s[i]);
            if (s[i] == '(')
                counter++;
        }
        else
        {
            counter--;
            while (!st.empty() && st.top() != '(')
            {
                reverse += st.top();
                st.pop();
            }
            st.pop();
            for (int i = 0; i < reverse.length(); i++)
                st.push(reverse[i]);
            reverse = "";
        }
        if (counter == 0 && i == s.length() - 1)
            break;
    }
    while (!st.empty())
    {
        reverse = st.top() + reverse;
        st.pop();
    }
    return reverse;
}

// Approch-2
string reverseParentheses(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            int open = st.top();
            int close = i;
            st.pop();
            reverse(s.begin() + open + 1, s.begin() + close);
        }
    }
    string ans;
    for (auto it : s)
    {
        if (it != '(' && it != ')')
        {
            ans.push_back(it);
        }
    }
    return ans;
}