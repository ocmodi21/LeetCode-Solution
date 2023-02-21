#include <bits/stdc++.h>
using namespace std;

// Approch-1 => Using Sort
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            return nums[i];
    }
    return -1;
}

// Approch-2 => Using BS
int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];
    int l = 0, h = nums.size() - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            return nums[mid];
        else if ((nums[mid] == nums[mid + 1] && mid % 2 == 0) || (nums[mid] == nums[mid - 1] && mid % 2 != 0))
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}