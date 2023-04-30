#include <bits/stdc++.h>
using namespace std;

int maximizeSum(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int maxScore = 0;
    while (k--)
    {
        int temp = nums[nums.size() - 1];
        maxScore += temp;
        nums[nums.size() - 1] = temp + 1;
    }
    return maxScore;
}