#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s)
{
    int n = s.size();
    string ans = s;

    for (int i = 0; i < n / 2; i++)
    {
        char ch = ans[n - 1];
        ans.pop_back();
        ans = ch + ans;
        if (ans == s)
            return true;
    }
    return false;
}