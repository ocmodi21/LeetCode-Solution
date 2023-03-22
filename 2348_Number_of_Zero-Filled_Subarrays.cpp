#include <bits/stdc++.h>
using namespace std;

// Approch-1
long long zeroFilledSubarray(vector<int> &nums)
{
    long long counter = 0;
    long long current = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        current++;
        if (nums[i] != 0)
            current = 0;
        counter += current;
    }
    return counter;
}

// Approch-2
long long zeroFilledSubarray(vector<int> &nums)
{
    long long ans = 0;
    long long count = 0;
    for (int i = 0; i <= nums.size(); i++)
    {
        if (i < nums.size() && nums[i] == 0)
            count++;
        else if (count != 0)
        {
            ans = ans + ((count * (count + 1)) / 2);
            count = 0;
        }
    }
    return ans;
}