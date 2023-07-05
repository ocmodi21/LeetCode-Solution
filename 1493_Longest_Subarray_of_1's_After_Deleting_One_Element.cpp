#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int i = 0, j = 0, ans = 0, zeros = 0;

    while (j < nums.size())
    {
        if (nums[j] == 0)
            zeros++;
        while (zeros > 1)
        {
            if (nums[i] == 0)
                zeros--;
            i++;
        }
        ans = max(ans, j - i + 1 - zeros);
        j++;
    }
    return (ans == nums.size()) ? ans - 1 : ans;
}