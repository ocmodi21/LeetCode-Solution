#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    int n = s.length();
    string uniques = "";
    stack<char> st;
    vector<int> mp(26, 0);
    vector<bool> visited(26, false);

    for (int i = 0; i < n; i++)
        mp[s[i] - 'a']++;

    for (int i = 0; i < n; i++)
    {
        mp[s[i] - 'a']--;
        if (!visited[s[i] - 'a'])
        {
            while (st.size() > 0 && st.top() > s[i] && mp[st.top() - 'a'] > 0)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
    }

    while (!st.empty())
    {
        uniques += st.top();
        st.pop();
    }
    reverse(uniques.begin(), uniques.end());
    return uniques;
}