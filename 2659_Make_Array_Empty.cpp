#include <bits/stdc++.h>
using namespace std;

long long countOperationsToEmptyArray(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]] = i;

    long long count = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (mp[nums[i]] < mp[nums[i - 1]])
            count += nums.size() - i;
    }
    return count;
}