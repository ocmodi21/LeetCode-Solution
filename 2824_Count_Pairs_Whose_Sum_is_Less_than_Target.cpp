#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &nums, int target)
{
    int n = nums.size();
    int totalPair = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] < target)
                totalPair++;
        }
    }
    return totalPair;
}