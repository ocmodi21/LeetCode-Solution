#include <bits/stdc++.h>
using namespace std;

// Approch-1
string removeDuplicates(string s)
{
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (ans.size() != 0 && ans.back() == s[i])
        {
            ans.pop_back();
        }
        else
            ans.push_back(s[i]);
    }
    return ans;
}

// Approch-2
string removeDuplicates(string S)
{
    stack<char> ch;
    string add = "";

    for (auto c : S)
    {
        if (!ch.empty())
        {
            if (ch.top() == c)
                ch.pop();
            else
                ch.push(c);
        }
        else
            ch.push(c);
    }

    while (!ch.empty())
    {
        add += ch.top();
        ch.pop();
    }

    reverse(add.begin(), add.end());
    return add;
}