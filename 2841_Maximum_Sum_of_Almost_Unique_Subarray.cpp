#include <bits/stdc++.h>
using namespace std;

long long maxSum(vector<int> &nums, int m, int k)
{
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    long long ans = 0;
    long long sum = 0;

    while (j < nums.size())
    {
        sum += nums[j];
        mp[nums[j]]++;

        if (j - i + 1 == k)
        {
            if (mp.size() >= m)
            {
                ans = max(ans, sum);
            }
            sum -= nums[i];
            mp[nums[i]]--;

            if (mp[nums[i]] == 0)
            {
                mp.erase(nums[i]);
            }
            i++;
        }
        j++;
    }
    return ans;
}