#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0, ans = 0;
    int zeroCount = 0;

    while (j < nums.size())
    {
        if (nums[j] == 0)
            zeroCount++;
        if (zeroCount <= k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (zeroCount > k)
        {
            while (zeroCount > k)
            {
                if (nums[i] == 0)
                {
                    zeroCount--;
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}