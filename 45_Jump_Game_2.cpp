#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    vector<int> maxStep;
    maxStep.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
        maxStep.push_back(max(nums[i] + i, maxStep[i - 1]));

    int i = 0;
    int jumpCounter = 0;
    while (i < maxStep.size() - 1)
    {
        jumpCounter++;
        i = maxStep[i];
    }
    return jumpCounter;
}