#include <bits/stdc++.h>
using namespace std;

// Approch-1
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (auto i : nums)
        m[i]++;
    for (auto x : m)
    {
        if (x.second == 1)
            return x.first;
    }
    return -1;
}

// Approch-2
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
        ans ^= nums[i];
    return ans;
}