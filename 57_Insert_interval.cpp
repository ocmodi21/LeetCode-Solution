#include <bits/stdc++.h>
using namespace std;

// Approch-1
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

// Approch-2
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> updatedIntervals;
    vector<int> tempInterval = newInterval;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][0] > newInterval[1])
        {
            updatedIntervals.push_back(tempInterval);
            tempInterval = intervals[i];
        }
        else if (intervals[i][1] < newInterval[0])
            updatedIntervals.push_back(intervals[i]);
        else
        {
            tempInterval[0] = min(tempInterval[0], intervals[i][0]);
            tempInterval[1] = max(tempInterval[1], intervals[i][1]);
        }
    }
    updatedIntervals.push_back(tempInterval);
    return updatedIntervals;
}