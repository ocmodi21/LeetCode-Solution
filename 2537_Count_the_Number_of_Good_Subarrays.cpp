#include <bits/stdc++.h>
using namespace std;

long long countGood(vector<int> &nums, int k)
{
    long long ans = 0;
    long long curr = 0;
    unordered_map<int, int> mp;

    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        while (j < nums.size() && curr < k)
        {
            curr += mp[nums[j]]++;
            j++;
        }
        if (curr >= k)
        {
            ans += nums.size() - j + 1;
        }
        curr -= --mp[nums[i]];
    }
    return ans;
}