#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        sum %= k;

        if (i && sum == 0)
            return true;
        if (m.find(sum) != m.end())
        {
            if (i - m[sum] > 1)
                return true;
        }
        else
            m[sum] = i;
    }
    return false;
}