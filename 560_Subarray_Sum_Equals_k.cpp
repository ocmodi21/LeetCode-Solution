#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int sum = 0, ans = 0;
    unordered_map<int, int> mp;
    mp[sum]++;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (mp.find(sum - k) != mp.end())
            ans += mp[sum - k];
        mp[sum]++;
    }
    return ans;
}