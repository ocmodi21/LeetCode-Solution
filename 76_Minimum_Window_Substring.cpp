#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    string minString;
    int Counter = s.length();
    for (int i = 0; i < t.length(); i++)
        mp[t[i]]++;

    int mpSize = mp.size();
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                mpSize--;
        }
        if (mpSize == 0)
        {
            while (j < i)
            {
                if (mp.find(s[j]) == mp.end())
                    j++;
                else if (mp.find(s[j]) != mp.end() && mp[s[j]] < 0)
                {
                    mp[s[j]]++;
                    if (mp[s[j]] == 1)
                        mpSize++;
                    j++;
                }
                else if (mp.find(s[j]) != mp.end() && mp[s[j]] == 0)
                    break;
            }
            if (i - j + 1 <= Counter)
            {
                minString = s.substr(j, i - j + 1);
                Counter = i - j + 1;
            }
        }
    }
    return minString;
}