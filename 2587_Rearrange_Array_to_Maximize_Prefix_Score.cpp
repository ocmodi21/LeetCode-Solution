#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> temp(nums.size(), 0);
    long long sum = 0;
    long long maxi = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        sum += nums[i];
        temp[i] = sum;
        if (sum > 0)
            maxi++;
    }
    return maxi;
}