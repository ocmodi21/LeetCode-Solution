#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> ds;

void findSubset(int ind, vector<int> &arr)
{
    ans.push_back(ds);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        findSubset(i + 1, arr);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    findSubset(0, nums);
    return ans;
}