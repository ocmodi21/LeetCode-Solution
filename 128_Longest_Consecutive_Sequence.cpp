#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int longest = 0;
    int cur_longest = 1;

    if (!nums.size())
        return 0;
    else
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else if (nums[i] == nums[i - 1] + 1)
                cur_longest++;
            else
            {
                longest = max(longest, cur_longest);
                cur_longest = 1;
            }
        }
    }
    return max(longest, cur_longest);
}