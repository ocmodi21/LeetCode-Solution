#include <bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> &nums, int left, int right)
{
    if (left == right)
        return nums[left];

    int leftScore = nums[left] - maxDiff(nums, left + 1, right);
    int rightScore = nums[right] - maxDiff(nums, left, right - 1);
    return max(leftScore, rightScore);
}

bool PredictTheWinner(vector<int> &nums)
{
    if (maxDiff(nums, 0, nums.size() - 1) >= 0)
        return true;
    return false;
}