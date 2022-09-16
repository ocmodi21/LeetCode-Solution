#include <bits/stdc++.h>
using namespace std;

// Approch-1 =>Time Complexity o(n)
vector<int> runningSum(vector<int> &nums)
{
    vector<int> v;

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        sum += nums[i];
        v.push_back(sum);
    }
    return v;
}