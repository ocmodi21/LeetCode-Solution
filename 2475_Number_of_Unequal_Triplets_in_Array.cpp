#include <bits/stdc++.h>
using namespace std;

int unequalTriplets(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] != nums[j] && nums[j] != nums[k] && nums[k] != nums[i])
                    count++;
            }
        }
    }
    return count;
}