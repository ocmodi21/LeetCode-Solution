#include <bits/stdc++.h>
using namespace std;

int longestAlternatingSubarray(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0 && nums[i] <= threshold)
        {
            int cnt = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] % 2 != nums[j - 1] % 2 && nums[j] <= threshold)
                    cnt++;
                else
                    break;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}