#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int start, int end)
{
    if (start == end)
        return true;
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void helper(int ind, string &s, vector<string> &ds, vector<vector<string>> &ans)
{
    if (ind == s.size() && ds.size() > 0)
        ans.push_back(ds);

    for (int i = ind; i < s.size(); i++)
    {
        if (checkPalindrome(s, ind, i))
        {
            ds.push_back(s.substr(ind, i - ind + 1));
            helper(i + 1, s, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    helper(0, s, ds, ans);
    return ans;
}