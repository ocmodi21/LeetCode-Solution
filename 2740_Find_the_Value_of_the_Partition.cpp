#include <bits/stdc++.h>
using namespace std;

int findValueOfPartition(vector<int> &nums)
{
    int ans = 1e9;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        ans = min(ans, nums[i] - nums[i - 1]);
    }
    return ans;
}
