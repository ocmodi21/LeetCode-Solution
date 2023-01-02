#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    long long ans = 0, sum = 0;
    unordered_map<int, int> mp;

    while (j < nums.size())
    {
        mp[nums[j]]++;
        sum += nums[j];

        while (mp.size() > k || mp.size() < j - i + 1)
        {
            mp[nums[i]]--;
            sum -= nums[i];
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
        }

        if (mp.size() == k && j - i + 1 == k)
        {
            ans = max(ans, sum);
        }
        j++;
    }
    return ans;
}