#include <bits/stdc++.h>
using namespace std;

int minimizeMax(vector<int> &nums, int p)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int start = 0, end = nums.back();

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] <= mid)
            {
                count += 1;
                i += 1;
            }
        }

        if (count < p)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}