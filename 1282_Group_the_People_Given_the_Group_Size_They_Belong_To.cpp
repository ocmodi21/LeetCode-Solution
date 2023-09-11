#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
    int n = groupSizes.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> ans;
    for (auto it : mp)
    {
        vector<int> tempAns;
        int reqSize = it.first;
        int currSize = it.second.size();

        for (int i = 1; i <= currSize; i++)
        {
            tempAns.push_back(it.second[i - 1]);
            if (i % reqSize == 0)
            {
                ans.push_back(tempAns);
                tempAns.clear();
            }
        }
    }
    return ans;
}