#include <bits/stdc++.h>
using namespace std;

int specialArray(vector<int> &nums)
{
    int low = 1, high = nums.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2, cnt = 0;
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] >= mid)
                cnt++;
        }
        if (cnt == mid)
            return mid;
        else if (cnt < mid)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}