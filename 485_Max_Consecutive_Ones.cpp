#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int curCount = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            curCount++;
            ans = max(ans, curCount);
        }
        else
            curCount = 0;
    }
    return ans;
}