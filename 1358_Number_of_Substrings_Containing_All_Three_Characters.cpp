#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    int i = 0, j = 0;
    int ans = 0;
    unordered_map<char, int> mp;

    while (j < s.size())
    {
        mp[s[j]]++;
        while (mp['a'] && mp['b'] && mp['c'])
        {
            ans += (s.size() - j);
            mp[s[i]]--;
            i++;
        }
        j++;
    }
    return ans;
}