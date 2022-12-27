#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    int ans = 0;
    unordered_map<int, int> mp;

    while (j < nums.size())
    {
        mp[nums[j]]++;
        if (mp.size() <= k)
        {
            ans += (j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            if (mp.size() <= k)
                ans += (j - i + 1);
            j++;
        }
    }
    return ans;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}