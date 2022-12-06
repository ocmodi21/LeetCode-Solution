#include <bits/stdc++.h>
using namespace std;

int averageValue(vector<int> &nums)
{
    int sum = 0, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 3 == 0 && nums[i] % 2 == 0)
        {
            sum += nums[i];
            count++;
        }
    }
    if (count)
        return (sum / count);
    return 0;
}