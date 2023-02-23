#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> nums, int k, int mid)
{
    int sum = 0;
    int subArray = 1;
    for (int it : nums)
    {
        if (sum + it <= mid)
        {
            sum += it;
        }
        else
        {
            subArray++;
            sum = it;
        }
    }
    if (subArray > k)
        return false;
    return true;
}
int splitArray(vector<int> &nums, int k)
{
    int low = 0, high = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(nums, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}