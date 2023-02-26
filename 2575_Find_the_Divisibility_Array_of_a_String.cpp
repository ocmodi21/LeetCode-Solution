#include <bits/stdc++.h>
using namespace std;

vector<int> divisibilityArray(string word, int m)
{
    vector<int> ans;
    long val = 0;
    for (auto &c : word)
    {
        val = (10 * val + (c - '0')) % m;
        if (val == 0)
            ans.push_back(1);
        else
            ans.push_back(0);
    }
    return ans;
}