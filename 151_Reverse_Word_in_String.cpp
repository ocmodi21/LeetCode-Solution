#include <bits/stdc++.h>
using namespace std;

// Approch-1
string reverseWords(string s)
{
    stack<string> st;
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (temp.size() > 0)
                st.push(temp);
            temp = "";
        }
        else
            temp += s[i];
    }
    if (temp.size() > 0)
        st.push(temp);
    temp = "";
    while (!st.empty())
    {
        temp += st.top();
        st.pop();
        if (!st.empty())
            temp += " ";
    }
    return temp;
}

//Approch-2
