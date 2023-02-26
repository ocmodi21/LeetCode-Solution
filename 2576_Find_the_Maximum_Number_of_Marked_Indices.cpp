#include <bits/stdc++.h>
using namespace std;

int maxNumOfMarkedIndices(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), j = n - 1;
    int ans = 0;
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        if (nums[i] * 2 <= nums[j])
        {
            ans += 2;
            j -= 1;
        }
    }
    return ans;
}