#include <bits/stdc++.h>
using namespace std;

int countCompleteSubarrays(vector<int> &nums)
{
    unordered_map<int, int> mp1, mp2;
    for (auto it : nums)
        mp1[it]++;

    int i = 0, j = 0, ans = 0, n = nums.size();
    while (j < n)
    {
        mp2[nums[j]]++;
        while (mp1.size() == mp2.size())
        {
            ans += (n - j);
            mp2[nums[i]]--;
            if (mp2[nums[i]] == 0)
                mp2.erase(nums[i]);
            i++;
        }
        j++;
    }
    return ans;
}