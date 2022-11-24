#include <bits/stdc++.h>
using namespace std;

// Approch-1
int findMin(vector<int> &nums)
{
    return *min_element(nums.begin(), nums.end());
}

// Approch-2
int findMin(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    if (nums[low] < nums[high])
        return nums[low];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else if (nums[mid] < nums[high])
            high = mid;
        else
            high--;
    }
    return nums[low];
}