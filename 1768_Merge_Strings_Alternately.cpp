#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    string ans = "";
    int i = 0, j = 0;
    while (i < word1.size() && j < word2.size())
    {
        ans += word1[i++];
        ans += word2[j++];
    }
    while (i < word1.size())
        ans += word1[i++];
    while (j < word2.size())
        ans += word2[j++];
    return ans;
}