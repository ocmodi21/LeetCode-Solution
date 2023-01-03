#include <bits/stdc++.h>
using namespace std;

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