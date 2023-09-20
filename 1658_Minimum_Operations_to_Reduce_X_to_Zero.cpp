#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int x)
{
    int target = 0, n = nums.size();
    for (auto it : nums)
        target += it;
    target -= x;
    if (target == 0)
        return n;

    int minOperation = 0;
    int i = 0, j = 0, currSum = 0;
    while (j < n)
    {
        currSum += nums[j];
        while (i <= j && currSum > target)
        {
            currSum -= nums[i];
            i++;
        }
        if (currSum == target)
        {
            minOperation = max(minOperation, j - i + 1);
        }
        j++;
    }
    return minOperation ? n - minOperation : -1;
}