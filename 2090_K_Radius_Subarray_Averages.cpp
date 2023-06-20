#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int> &nums, int k)
{
    vector<int> ans(nums.size(), -1);
    int i = 0, j = 0;
    long long sum = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        if ((j - i + 1) == (2 * k + 1))
        {
            ans[j - k] = sum / (2 * k + 1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return ans;
}