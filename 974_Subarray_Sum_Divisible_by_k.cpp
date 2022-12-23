#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int sum = 0, rem = 0;
    int ans = 0;
    unordered_map<int, int> mp;
    mp[sum]++;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        rem = sum % k;
        if (rem < 0)
            rem += k;
        if (mp.find(rem) != mp.end())
            ans += mp[rem];
        mp[rem]++;
    }
    return ans;
}