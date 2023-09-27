#include <bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t)
{
    unordered_map<char, int> mp;
    for (auto it : s)
        mp[it]++;
    for (auto it : t)
        if (--mp[it] < 0)
            return it;
    return '\0';
}