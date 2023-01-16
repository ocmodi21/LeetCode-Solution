#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    // Apply merge interval logic
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> temp = intervals[0];
    for (auto it : intervals)
    {
        if (temp[1] >= it[0])
        {
            temp[1] = max(it[1], temp[1]);
        }
        else
        {
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}