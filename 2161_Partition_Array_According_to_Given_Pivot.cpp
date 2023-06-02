#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> temp, lesser, greater;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == pivot)
            temp.push_back(nums[i]);
        else if (nums[i] < pivot)
            lesser.push_back(nums[i]);
        else if (nums[i] > pivot)
            greater.push_back(nums[i]);
    }
    nums.clear();
    nums.insert(nums.begin(), lesser.begin(), lesser.end());
    nums.insert(nums.end(), temp.begin(), temp.end());
    nums.insert(nums.end(), greater.begin(), greater.end());
    return nums;
}