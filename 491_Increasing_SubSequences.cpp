#include <bits/stdc++.h>
using namespace std;

void helper(int idx, vector<int> &nums, vector<int> &res, set<vector<int>> &ans, int prev)
{
    if (idx == nums.size())
    {
        if (res.size() >= 2)
            ans.insert(res);
        return;
    }

    if (nums[idx] >= prev)
    {
        res.push_back(nums[idx]);
        helper(idx + 1, nums, res, ans, nums[idx]);
        res.pop_back();
    }
    helper(idx + 1, nums, res, ans, prev);
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<int> res;
    set<vector<int>> ans;
    helper(0, nums, res, ans, INT_MIN);
    vector<vector<int>> result;
    for (auto it : ans)
        result.push_back(it);
    return result;
}