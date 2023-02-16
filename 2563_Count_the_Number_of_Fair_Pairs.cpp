#include <bits/stdc++.h>
using namespace std;

// Approch-1
long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), low = n - 1, high = n - 1;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        while (0 <= high && nums[i] + nums[high] > upper)
            --high;
        while (0 <= low && nums[i] + nums[low] >= lower)
            --low;
        ans += high - low;
        if (i > low && i <= high)
            --ans;
    }
    return ans / 2;
}

// Approch-2
long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int left = i + 1;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] + nums[i] < lower)
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        int leftest = left;
        left = i + 1;
        right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] + nums[i] > upper)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        int rightest = right;
        ans += (rightest - leftest + 1);
    }
    return ans;
}