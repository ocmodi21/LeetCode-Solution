#include <bits/stdc++.h>
using namespace std;

// Approch-1
vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
{
    map<int, int> mpp;
    vector<vector<int>> ans;
    for (int i = 0; i < nums1.size(); i++)
        mpp[nums1[i][0]] += nums1[i][1];
    for (int i = 0; i < nums2.size(); i++)
        mpp[nums2[i][0]] += nums2[i][1];
    for (auto i : mpp)
    {
        vector<int> temp(2);
        temp[0] = i.first;
        temp[1] = i.second;
        ans.push_back(temp);
    }
    return ans;
}

// Approch-2
vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
{
    vector<vector<int>> ans;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i][0] == nums2[j][0])
        {
            ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            i++;
            j++;
        }
        else if (nums1[i][0] < nums2[j][0])
        {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        else
        {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }
    }
    for (; i < nums1.size(); i++)
    {
        ans.push_back({nums1[i][0], nums1[i][1]});
    }
    for (; j < nums2.size(); j++)
    {
        ans.push_back({nums2[j][0], nums2[j][1]});
    }
    return ans;
}