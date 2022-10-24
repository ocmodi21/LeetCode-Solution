#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int eve = 0, odd = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            ans[eve] = nums[i];
            eve += 2;
        }
        else
        {
            ans[odd] = nums[i];
            odd += 2;
        }
    }
    return ans;
}