#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Using Binary Search
int findMaxK(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        if (-nums[i] == nums[j])
        {
            int x = -nums[i];
            i++;
            j--;
            return x;
        }
        else if (-nums[i] < nums[j])
            j--;
        else
            i++;
    }
    return -1;
}

// Approch-1 =>using Set
int findMaxK(vector<int> &nums)
{
    int n = nums.size();
    set<int> s(nums.begin(), nums.end());
    int res = -1;
    for (int i = 0; i < n; ++i)
    {
        if (s.find(-nums[i]) != s.end())
            res = max(res, nums[i]);
    }
    return res;
}

// Approch-3 =>Using Map
int findMaxK(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto it : nums)
        mp[it]++;
    int mx = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0 && mp[-nums[i]] > 0)
        {
            mx = max(mx, nums[i]);
        }
    }
    return mx;
}