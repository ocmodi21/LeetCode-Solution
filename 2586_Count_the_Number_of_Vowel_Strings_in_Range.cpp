#include <bits/stdc++.h>
using namespace std;

bool isVowel(string &s)
{
    int n = s.length();
    if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u'))
        return true;
    return false;
}

int vowelStrings(vector<string> &words, int left, int right)
{
    int ans = 0;
    for (int i = left; i <= right; i++)
    {
        if (isVowel(words[i]))
            ans++;
    }
    return ans;
}