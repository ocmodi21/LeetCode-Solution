#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &s)
{
    int n = s.size();
    stack<long long> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/")
        {
            long long a = st.top();
            st.pop();
            long long b = st.top();
            st.pop();
            if (s[i] == "+")
                st.push(b + a);
            else if (s[i] == "-")
                st.push(b - a);
            else if (s[i] == "*")
                st.push(b * a);
            else if (s[i] == "/")
                st.push(b / a);
        }
        else
        {
            st.push(stoi(s[i]));
        }
    }
    return st.top();
}