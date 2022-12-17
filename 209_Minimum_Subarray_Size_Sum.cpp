#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int minlength = INT_MAX;
    while (j < nums.size())
    {
        sum += nums[j];
        if (sum < target)
        {
            j++;
        }
        if (sum >= target)
        {
            while (sum >= target)
            {
                minlength = min(minlength, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    return (minlength == INT_MAX) ? 0 : minlength;
}