#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans = nums[0] > 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = i + 1;
        if (cnt > nums[i] && (i + 1 == nums.size() || cnt < nums[i + 1]))
        {
            ans++;
        }
    }
    return ans;
}