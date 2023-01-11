#include <bits/stdc++.h>
using namespace std;

int minIncrementForUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
        {
            ans = ans + (nums[i] - nums[i + 1]) + 1;
            nums[i + 1] = nums[i] + 1;
        }
    }
    return ans;
}