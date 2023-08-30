#include <bits/stdc++.h>
using namespace std;

long long minimumReplacement(vector<int> &nums)
{
    int n = nums.size();
    long long counter = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {
            long long tempCount = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
            counter += tempCount - 1;
            nums[i] /= tempCount;
        }
    }
    return counter;
}