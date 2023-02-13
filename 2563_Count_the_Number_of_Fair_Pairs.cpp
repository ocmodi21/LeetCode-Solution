#include <bits/stdc++.h>
using namespace std;

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