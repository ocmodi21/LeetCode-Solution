#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findMatrix(vector<int> &a)
{
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    int minRows = 1;
    for (int i = 0; i < a.size(); i++)
        mp[a[i]]++;
    for (auto i : mp)
        minRows = max(minRows, i.second);

    while (minRows--)
    {
        vector<int> temp;
        for (auto j : mp)
        {
            if (j.second > 0)
                temp.push_back(j.first);
            mp[j.first]--;
        }
        ans.push_back(temp);
    }
    return ans;
}