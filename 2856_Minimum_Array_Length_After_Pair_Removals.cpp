#include <bits/stdc++.h>
using namespace std;

int minLengthAfterRemovals(vector<int> &nums)
{
    int n = nums.size();
    int res = n;
    int mid = (n + 1) / 2;

    for (int i = 0; i < n / 2; i++)
    {
        if (nums[i] < nums[i + mid])
            res -= 2;
    }
    return res;
}