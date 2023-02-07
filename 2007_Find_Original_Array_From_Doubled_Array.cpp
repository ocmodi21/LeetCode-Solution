#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int> &changed)
{
    unordered_map<int, int> mp;
    vector<int> ans;
    sort(changed.begin(), changed.end());

    for (int i = 0; i < changed.size(); i++)
    {
        if (mp[changed[i]] == 0)
        {
            ans.push_back(changed[i]);
            mp[2 * changed[i]]++;
        }
        else
        {
            mp[changed[i]]--;
        }
    }
    return (ans.size() == changed.size() / 2) ? ans : vector<int>{};
}