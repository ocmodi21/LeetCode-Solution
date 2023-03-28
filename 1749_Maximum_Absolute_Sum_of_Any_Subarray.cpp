#include <bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int> &nums)
{
    int maxSum = INT_MIN, minSum = INT_MAX, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }

    sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        minSum = min(sum, minSum);
        if (sum > 0)
            sum = 0;
    }
    return max(maxSum, -minSum);
}