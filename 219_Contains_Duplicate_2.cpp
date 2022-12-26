#include <bits/stdc++.h>
using namespace std;

// Approch-1
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.count(nums[i]))
        {
            int diff = abs(mp[nums[i]] - i);
            if (diff <= k)
                return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}

// Approch-2-Sliding Window
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> set;
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (set.size() == k + 1)
        {
            set.erase(nums[i]);
            i++;
        }

        if (set.find(nums[j]) != set.end())
            return true;
        else
            set.insert(nums[j]);
    }
    return false;
}