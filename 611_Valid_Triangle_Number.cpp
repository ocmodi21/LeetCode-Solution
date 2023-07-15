#include <bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = nums.size() - 1; i >= 2; i--)
    {
        int low = 0;
        int high = i - 1;
        while (low < high)
        {
            if (nums[i] < nums[low] + nums[high])
            {
                ans += (high - low);
                high--;
            }
            else
            {
                low++;
            }
        }
    }
    return ans;
}