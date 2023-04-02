#include <bits/stdc++.h>
using namespace std;

int maximumCostSubstring(string s, string chars, vector<int> &vals)
{
    vector<int> v;
    int sum = 0, ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        auto ind = chars.find(s[i]);
        if (ind != string::npos)
            v.push_back(vals[ind]);
        else
            v.push_back((s[i] - 'a') + 1);
    }

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];

        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}