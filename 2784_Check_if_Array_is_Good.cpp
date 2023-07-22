#include <bits/stdc++.h>
using namespace std;

bool isGood(vector<int> &nums)
{
    if (nums.size() == 1)
        return false;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] != i + 1)
            return false;
    }
    return nums[nums.size() - 1] == nums[nums.size() - 2];
}