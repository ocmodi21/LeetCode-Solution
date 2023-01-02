#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    // Split s into words
    vector<string> words;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            words.push_back(temp);
            temp = "";
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    words.push_back(temp);

    if (pattern.length() < words.size() ||
        pattern.length() > words.size())
    {
        return false;
    }

    // Mapping pattern with words
    unordered_map<char, string> mp;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (mp.find(pattern[i]) == mp.end())
            mp[pattern[i]] = words[i];
        else if (mp[pattern[i]] != words[i])
            return false;
    }

    unordered_set<string> st;
    for (auto x : mp)
        st.insert(x.second);
    if (st.size() != mp.size())
        return false;
    return true;
}