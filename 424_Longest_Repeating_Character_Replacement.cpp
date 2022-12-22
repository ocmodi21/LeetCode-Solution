#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int i = 0, j = 0;
    unordered_map<char, int> mp;
    int ans = 0;
    int mx_element = 0;
    while (j < s.size())
    {
        mp[s[j]]++;
        mx_element = max(mx_element, mp[s[j]]);
        if (j - i + 1 - mx_element > k)
        {
            mp[s[i]]--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}