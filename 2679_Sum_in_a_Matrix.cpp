#include <bits/stdc++.h>
using namespace std;

int matrixSum(vector<vector<int>> &nums)
{
    for (int i = 0; i < nums.size(); i++)
        sort(nums[i].begin(), nums[i].end());

    int ans = 0;
    for (int col = 0; col < nums[0].size(); col++)
    {
        int temp = 0;
        for (int row = 0; row < nums.size(); row++)
        {
            temp = max(temp, nums[row][col]);
        }
        ans += temp;
    }
    return ans;
}