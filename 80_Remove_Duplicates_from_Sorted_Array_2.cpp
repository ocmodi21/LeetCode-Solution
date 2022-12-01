#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() < 3)
        return nums.size();
    int k = 2;
    for (int i = 2; i < nums.size(); i++)
        if (nums[k - 2] != nums[i])
            nums[k++] = nums[i];
    return k;
}