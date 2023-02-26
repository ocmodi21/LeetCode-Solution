#include <bits/stdc++.h>
using namespace std;

// Approch-1
vector<int> leftRigthDifference(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return {0};
    vector<int> left(n);
    vector<int> right(n);

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += nums[i];
        left[i + 1] = sum;
    }
    sum = 0;
    for (int i = n - 1; i > 0; i--)
    {
        sum += nums[i];
        right[i - 1] = sum;
    }
    vector<int> ans(n);
    for (int i = 0; i < left.size(); i++)
    {
        ans[i] = abs(left[i] - right[i]);
    }
    return ans;
}

// Approch-2
vector<int> leftRigthDifference(vector<int> &nums)
{
    int val = 0;
    for (auto &x : nums)
        val += x;
    vector<int> ans;
    for (auto &x : nums)
    {
        val -= x;
        ans.push_back(abs(val));
        val -= x;
    }
    return ans;
}