#include <bits/stdc++.h>
using namespace std;

int maximumCount(vector<int> &nums)
{
    int posCount = 0;
    int negCount = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            posCount++;
        if (nums[i] < 0)
            negCount++;
    }
    return (posCount >= negCount) ? posCount : negCount;
}